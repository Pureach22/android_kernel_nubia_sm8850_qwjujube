__int64 cnss_utils_smem_mailbox_write()
{
  __int64 v0; // x19
  __int64 v1; // x1

  v0 = cnss_utils_priv;
  if ( cnss_utils_priv )
  {
    if ( (*(_BYTE *)(cnss_utils_priv + 556) & 1) != 0 )
      return smem_mailbox_write(*(unsigned int *)(v0 + 560));
    if ( (unsigned int)smem_mailbox_start(*(unsigned int *)(cnss_utils_priv + 560), 0) == 1 )
    {
      *(_BYTE *)(v0 + 556) = 1;
      return smem_mailbox_write(*(unsigned int *)(v0 + 560));
    }
    printk(&unk_7366, v1);
  }
  return 4294967274LL;
}
