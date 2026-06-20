__int64 __fastcall aer_dev_correctable_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  __int64 v4; // x25
  __int64 v6; // x21
  __int64 v7; // x19
  int v8; // w0
  const char *v9; // x3
  __int64 v10; // x4

  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(_QWORD *)(v3 + 3056);
  if ( v4 )
  {
    v6 = 0;
    v7 = 0;
    while ( 1 )
    {
      v9 = (&aer_correctable_error_string)[v6];
      if ( v9 )
      {
        v8 = sysfs_emit_at(a3, (unsigned int)v7, "%s %llu\n", v9, *(_QWORD *)(v4 + 8 * v6));
      }
      else
      {
        v10 = *(_QWORD *)(v4 + 8 * v6);
        if ( !v10 )
          goto LABEL_5;
        v8 = sysfs_emit_at(a3, (unsigned int)v7, "dev_cor_errs_bit[%d] %llu\n", v6, v10);
      }
      v7 += v8;
LABEL_5:
      if ( ++v6 == 16 )
        return v7
             + (int)sysfs_emit_at(
                      a3,
                      (unsigned int)v7,
                      "TOTAL_%s %llu\n",
                      "ERR_COR",
                      *(_QWORD *)(*(_QWORD *)(v3 + 3056) + 560LL));
    }
  }
  return -19;
}
