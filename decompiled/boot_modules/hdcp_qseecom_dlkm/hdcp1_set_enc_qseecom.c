__int64 __fastcall hdcp1_set_enc_qseecom(__int64 *a1, char a2)
{
  __int64 v3; // x0
  _DWORD *v4; // x8
  __int64 v5; // x19
  void *v7; // x0

  if ( a1 && (v3 = *a1) != 0 )
  {
    if ( (a1[2] & 1) != 0 )
    {
      if ( (a1[3] & 1) != 0 )
      {
        v4 = *(_DWORD **)(v3 + 8);
        *v4 = 205;
        v4[1] = a2 & 1;
        v5 = *(_QWORD *)(v3 + 8);
        if ( (qseecom_send_command() & 0x80000000) != 0 )
        {
          v7 = &unk_C76B;
        }
        else
        {
          if ( !*(_DWORD *)(v5 + 68) )
            return 0;
          v7 = &unk_BDA5;
        }
        printk(v7);
      }
      else
      {
        printk(&unk_C830);
      }
    }
    else
    {
      printk(&unk_C905);
    }
  }
  else
  {
    printk(&unk_C470);
  }
  return 4294967274LL;
}
