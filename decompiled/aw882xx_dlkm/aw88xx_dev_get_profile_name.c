__int64 __fastcall aw88xx_dev_get_profile_name(__int64 a1, __int64 a2, unsigned int a3)
{
  const char *v4; // x20
  int v5; // w0
  __int64 *v7; // x8
  __int64 v8; // x1
  __int64 *v9; // x8
  __int64 v10; // x1

  if ( (a3 & 0x80000000) != 0 )
  {
    v7 = *(__int64 **)(a1 + 112);
    v8 = v7[14];
    if ( !v8 )
      v8 = *v7;
    printk(&unk_23EF3, v8, "aw88xx_dev_get_profile_name");
    return 4294967274LL;
  }
  else if ( *(_DWORD *)(a1 + 624) < a3 )
  {
    v9 = *(__int64 **)(a1 + 112);
    v10 = v9[14];
    if ( !v10 )
      v10 = *v9;
    printk(&unk_23185, v10, "aw88xx_dev_get_profile_name");
    return 4294967274LL;
  }
  else
  {
    v4 = *(const char **)(*(_QWORD *)(a1 + 632) + 8LL
                                                * *(int *)(*(_QWORD *)(a1 + 640) + ((unsigned __int64)a3 << 6) + 4));
    strlen(v4);
    v5 = sized_strscpy(a2, v4);
    return v5 & (unsigned int)(v5 >> 31);
  }
}
