#include "pv.h"

void
encrypt_file (const char *ctxt_fname, void *raw_sk, size_t raw_len, int fin)
{
  /*************************************************************************** 
   * Task: Read the content from file descriptor fin, encrypt it using raw_sk,
   *       and place the resulting ciphertext in a file named ctxt_fname.
   *       The encryption should be CCA-secure, which is the level of 
   *       cryptographic protection that you should always expect of any 
   *       implementation of an encryption algorithm.
   * 
   * As we have learned in class, the gold standard for encryption is
   * CCA-security. The approach that we will take in this lab is to
   * use AES in CTR-mode (AES-CTR), and then append an AES-CBC-MAC mac
   * of the resulting ciphertext. (Always mac after encrypting!) The
   * dcrypt library contains an implementation of AES (see source at
   * ~nicolosi/devel/libdcrypt/src/aes.c), but you need to implement
   * the logic for using AES in CTR-mode and in CBC-MAC'ing.
   *
   * Notice that the keys used to compute AES-CTR and AES-CBC-MAC mac
   * must be different. Never use the same cryptographic key for two
   * different purposes: bad interference could occur.  For this
   * reason, the key raw_sk actually consists of two pieces, one for
   * use in AES-CTR and the other for AES-CBC-MAC. The length of each
   * piece (and hence the cryptographic strength of the encryption) is
   * specified by the constant CCA_STRENGTH in pv.h; the default is
   * 128 bits, or 16 bytes.
   * 
   * Recall that AES works on blocks of 128 bits; in the case that the
   * length (in bytes) of the plaintext is not a multiple of 16, just
   * discard the least-significant bytes that you obtains from the
   * CTR-mode operation.
   * 
   * Thus, the overall layout of an encrypted file will be:
   *
   *         +--------------------------+---+
   *         |             Y            | W |
   *         +--------------------------+---+
   *
   * where Y = AES-CTR (K_CTR, plaintext)
   *       W = AES-CBC-MAC (K_MAC, Y)
   *
   * As for the sizes of the various components of a ciphertext file,
   * notice that:
   *
   * - the length of Y (in bytes) is just 16 bytes more than the length
   *   of the plaintext, and thus it may not be a multiple of 16; 
   * - the hash value AES-CBC-MAC (K_MAC, Y) is 16-byte long;
   *
   ***************************************************************************/

  /* Create the ciphertext file---the content will be encrypted, 
   * so it can be world-readable! */
	int fout = open(ctxt_fname, O_WRONLY | O_RDONLY |O_CREAT, 0600 );
	
	

  /* initialize the pseudorandom generator (for the IV) */
	int i;
	int blocksize = CCA_STRENGTH;
	int* aes_ctr_key = raw_sk;
	int* aes_cbc_mac_key = raw_sk + CCA_STRENGTH;
	char* c = malloc(blocksize);	
	char* read_buffer = malloc(blocksize);
	char* ctr_output = malloc(blocksize);
	int result;
	aes_ctx aes_ctr_struct;
	aes_ctx aes_cbc_struct;
	int* nonce = malloc(blocksize);
	int seed;
	
	if(fout <= 0){
	  printf("unable to create file");
	  exit(1);
	}
	
	
	
	aes_setkey(&aes_ctr_struct, aes_ctr_key, blocksize);
	aes_setkey(&aes_cbc_struct, aes_cbc_mac_key, blocksize);
	
	
	seed = time(NULL);	
	prng_seed(&seed, 4);
	prng_getbytes(c, blocksize);
	memcpy(nonce, c, blocksize);
	result = write(fout, c, blocksize);
	if(result <= 0){
	  printf("unable to write to file");
	  exit(1);
	}
	result = read(fin, read_buffer, blocksize);

	while(result > 0){
		if(result < blocksize){
			for(i = result; i < blocksize; i++){
				read_buffer[i] = 0;
		}
	}  
	aes_encrypt(&aes_ctr_struct, ctr_output, nonce); 			
	  for(i = 0; i < blocksize; i++){
	    *(ctr_output + i) = *(ctr_output + i)^*(read_buffer + i);
	  }
	if(result < blocksize){
		for(i = 0; i < result; i++){
			result = write(fout, &ctr_output[i], 1);
		}
	} else{
		result = write(fout, ctr_output, blocksize);
	} 
	  for(i = 0; i < blocksize; i++){
	    *(ctr_output + i) = *(ctr_output + i)^*(c + i);
		}
	  aes_encrypt(&aes_cbc_struct, c, ctr_output);
	  result = read(fin, read_buffer, blocksize);
	  *(nonce + 3) += 1;	
	}
	result = write(fout, c, blocksize);
	
	
	close(fout);
	free(c);
	free(read_buffer);
	aes_clrkey(&aes_ctr_struct);
	aes_clrkey(&aes_cbc_struct);
	free(ctr_output);
	free(nonce);
  

  /* The buffer for the symmetric key actually holds two keys: */
  /* use the first key for the AES-CTR encryption ...*/

  /* ... and the second part for the AES-CBC-MAC */

  /* Now start processing the actual file content using symmetric encryption */
  /* Remember that CTR-mode needs a random IV (Initialization Vector) */

  /* Compute the AES-CBC-MAC while you go */

  /* Don't forget to pad the last block with trailing zeroes */

  /* write the last chunk */

  /* Finish up computing the AES-CBC-MAC and write the resulting
   * 16-byte MAC after the last chunk of the AES-CTR ciphertext */
}

void 
usage (const char *pname)
{
  printf ("Personal Vault: Encryption \n");
  printf ("Usage: %s SK-FILE PTEXT-FILE CTEXT-FILE\n", pname);
  printf ("       Exits if either SK-FILE or PTEXT-FILE don't exist.\n");
  printf ("       Otherwise, encrpyts the content of PTEXT-FILE under\n");
  printf ("       sk, and place the resulting ciphertext in CTEXT-FILE.\n");
  printf ("       If CTEXT-FILE existed, any previous content is lost.\n");

  exit (1);
}

int 
main (int argc, char **argv)
{
  int fdsk, fdptxt;
  char *raw_sk;
  size_t raw_len;

  /* YOUR CODE HERE */


  if (argc != 4) {
    usage (argv[0]);
  }   /* Check if argv[1] and argv[2] are existing files */
  else if (((fdsk = open (argv[1], O_RDONLY)) == -1)
	   || ((fdptxt = open (argv[2], O_RDONLY)) == -1)) {
    if (errno == ENOENT) {
      usage (argv[0]);
    }
    else {
      perror (argv[0]);
      
      exit (-1);
    }
  }
  else {
    setprogname (argv[0]);
    
    /* Import symmetric key from argv[1] */
    if (!(import_sk_from_file (&raw_sk, &raw_len, fdsk))) {
      printf ("%s: no symmetric key found in %s\n", argv[0], argv[1]);
      
      close (fdsk);
      exit (2);
    }
    close (fdsk);
    
    /* Enough setting up---let's get to the crypto... */
    encrypt_file (argv[3], raw_sk, raw_len, fdptxt);    
    
    /* scrub the buffer that's holding the key before exiting */
    *raw_sk = 0;
	argv[1] = 0;
	/* YOUR CODE HERE */
	
	close (fdptxt);
  }

  return 0;
}
