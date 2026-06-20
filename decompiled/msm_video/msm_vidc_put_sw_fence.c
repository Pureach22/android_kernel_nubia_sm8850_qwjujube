__int64 __fastcall msm_vidc_put_sw_fence(__int64 a1, char *a2)
{
  __int64 **v2; // x8
  __int64 v4; // x9
  __int64 *v5; // x10
  __int64 v6; // x8
  const char *v8; // x6
  int v15; // w8
  int v17; // w8

  v2 = *((__int64 ***)a2 + 1);
  v4 = a1;
  if ( *v2 == (__int64 *)a2 && (v5 = *(__int64 **)a2, *(char **)(*(_QWORD *)a2 + 8LL) == a2) )
  {
    v5[1] = (__int64)v2;
    *v2 = v5;
  }
  else
  {
    _list_del_entry_valid_or_report(a2);
  }
  *(_QWORD *)a2 = a2;
  *((_QWORD *)a2 + 1) = a2;
  v6 = *((_QWORD *)a2 + 33);
  if ( v6 )
  {
    _X0 = (unsigned int *)(v6 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v15 = __ldxr(_X0);
    while ( __stlxr(v15 - 1, _X0) );
    if ( v15 == 1 )
    {
      __dmb(9u);
      dma_fence_release();
    }
    else if ( v15 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    vfree(a2);
  }
  else
  {
    if ( *((_QWORD *)a2 + 22) )
      v8 = (const char *)&unk_88630;
    else
      v8 = (const char *)&unk_823BB;
    snprintf(
      a2 + 16,
      0x80u,
      "%s%sfence: %s: %s: fd %3d id %10llu mid %5llu f.no %5llu",
      (const char *)(v4 + 340),
      ": ",
      *((const char **)a2 + 34),
      v8,
      *((_DWORD *)a2 + 38),
      *((_QWORD *)a2 + 20),
      *((_QWORD *)a2 + 20) & 0x7FFFFFFFLL,
      *((_QWORD *)a2 + 21));
    _X0 = (unsigned int *)(a2 + 240);
    __asm { PRFM            #0x11, [X0] }
    do
      v17 = __ldxr(_X0);
    while ( __stlxr(v17 - 1, _X0) );
    if ( v17 == 1 )
    {
      __dmb(9u);
      dma_fence_release();
    }
    else if ( v17 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  return 0;
}
