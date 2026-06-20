__int64 __fastcall smem_mailbox_start(int a1, void *a2)
{
  _UNKNOWN **v4; // x8

  if ( info_validated == 1 || (read_client_info_map() & 1) != 0 )
  {
    v4 = &smem_client_channel_list_head;
    do
    {
      v4 = (_UNKNOWN **)*v4;
      if ( v4 == &smem_client_channel_list_head )
      {
        v4 = &smem_client_channel_list_head;
        goto LABEL_9;
      }
    }
    while ( *((_DWORD *)v4 + 4) != a1 );
    if ( !v4 )
      goto LABEL_12;
LABEL_9:
    if ( *((_DWORD *)v4 + 4) != a1 )
    {
LABEL_12:
      printk(&unk_74DF);
      return 4294967274LL;
    }
    if ( *((_BYTE *)v4 + 32) == 1 )
    {
      printk(&unk_74A2);
      return 0xFFFFFFFFLL;
    }
    else
    {
      v4[8] = a2;
      *((_BYTE *)v4 + 32) = 1;
      return 1;
    }
  }
  else
  {
    printk(&unk_746A);
    return 4294967285LL;
  }
}
