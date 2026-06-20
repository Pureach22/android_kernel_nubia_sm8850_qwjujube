__int64 __fastcall hdcp2_app_init(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  unsigned int v3; // w0
  unsigned int v4; // w2

  if ( a1 && (v1 = *(_QWORD *)(a1 + 56)) != 0 )
  {
    v2 = *(_QWORD *)(v1 + 8);
    *(_DWORD *)v2 = 4107;
    if ( *(_BYTE *)(a1 + 76) == 1 )
    {
      printk(&unk_BF1F);
      return (unsigned int)-22;
    }
    else if ( (*(_BYTE *)(a1 + 48) & 1) != 0 )
    {
      printk(&unk_C130);
      return 0;
    }
    else
    {
      *(_DWORD *)(v2 + 4) = 131328;
      v3 = qseecom_send_command(*(_QWORD *)(a1 + 56), v2, 64, v2 + 64, 64);
      v4 = v3;
      if ( (v3 & 0x80000000) != 0 || *(_DWORD *)(v2 + 64) )
      {
        printk(&unk_C4E8);
        return (unsigned int)-22;
      }
      else if ( !v3 )
      {
        if ( *(_BYTE *)(v2 + 73) == 1 )
        {
          return 0;
        }
        else
        {
          printk(&unk_BE6A);
          return (unsigned int)-1;
        }
      }
    }
  }
  else
  {
    printk(&unk_CC25);
    return (unsigned int)-22;
  }
  return v4;
}
