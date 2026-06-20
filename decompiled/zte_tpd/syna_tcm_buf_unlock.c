__int64 __fastcall syna_tcm_buf_unlock(__int64 a1)
{
  __int64 v1; // x2
  char v2; // w8
  __int64 v4; // x19

  v1 = *(unsigned __int8 *)(a1 + 64);
  if ( (_DWORD)v1 == 1 )
  {
    v2 = 0;
  }
  else
  {
    v4 = a1;
    printk(&unk_38244, "syna_tcm_buf_unlock", v1);
    a1 = v4;
    v2 = *(_BYTE *)(v4 + 64) - 1;
  }
  *(_BYTE *)(a1 + 64) = v2;
  return mutex_unlock(a1 + 16);
}
