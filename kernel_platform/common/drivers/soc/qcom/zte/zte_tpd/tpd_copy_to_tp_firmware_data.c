__int64 __fastcall tpd_copy_to_tp_firmware_data(const char *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  unsigned __int64 *v4; // x8
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x22
  unsigned int v8; // w0
  unsigned int v9; // w19

  v3 = tpd_cdev;
  v4 = *(unsigned __int64 **)(tpd_cdev + 2720);
  if ( v4 && v4[1] )
  {
    v5 = *v4;
    if ( *v4 )
    {
      v6 = *(unsigned int *)(tpd_cdev + 1096);
      if ( v5 <= v6 )
      {
        return 0;
      }
      else
      {
        v8 = strlen(a1);
        if ( v5 >= (unsigned int)v6 + v8 )
          v9 = v8;
        else
          v9 = v5 - v6;
        memcpy(
          (void *)(*(_QWORD *)(*(_QWORD *)(tpd_cdev + 2720) + 8LL) + *(unsigned int *)(tpd_cdev + 1096)),
          a1,
          (int)v9);
        *(_DWORD *)(v3 + 1096) += v9;
      }
    }
    else
    {
      printk(unk_39CBE, a2, a3);
      return (unsigned int)-22;
    }
  }
  else
  {
    printk(unk_3BC9C, a2, a3);
    return (unsigned int)-12;
  }
  return v9;
}
