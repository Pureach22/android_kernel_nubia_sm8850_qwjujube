__int64 __fastcall aer_dev_fatal_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  __int64 v4; // x8
  __int64 v6; // x21
  __int64 v7; // x19
  __int64 v8; // x25
  int v9; // w0
  __int64 v10; // x4

  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(_QWORD *)(v3 + 3056);
  if ( v4 )
  {
    v6 = 0;
    v7 = 0;
    v8 = v4 + 128;
    while ( 1 )
    {
      if ( ((0xF8000FCEuLL >> v6) & 1) != 0 )
      {
        v10 = *(_QWORD *)(v8 + 8 * v6);
        if ( !v10 )
          goto LABEL_5;
        v9 = sysfs_emit_at(a3, (unsigned int)v7, "dev_fatal_errs_bit[%d] %llu\n", v6, v10);
      }
      else
      {
        v9 = sysfs_emit_at(
               a3,
               (unsigned int)v7,
               "%s %llu\n",
               (&aer_uncorrectable_error_string)[v6],
               *(_QWORD *)(v8 + 8 * v6));
      }
      v7 += v9;
LABEL_5:
      if ( ++v6 == 27 )
        return v7
             + (int)sysfs_emit_at(
                      a3,
                      (unsigned int)v7,
                      "TOTAL_%s %llu\n",
                      "ERR_FATAL",
                      *(_QWORD *)(*(_QWORD *)(v3 + 3056) + 568LL));
    }
  }
  return -19;
}
