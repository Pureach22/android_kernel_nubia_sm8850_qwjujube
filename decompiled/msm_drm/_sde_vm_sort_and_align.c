__int64 __fastcall sde_vm_sort_and_align(unsigned __int64 *a1)
{
  unsigned __int64 *i; // x8
  unsigned __int64 v3; // x10
  __int64 result; // x0
  unsigned __int64 *v5; // x20
  unsigned __int64 *v6; // x10
  unsigned __int64 v7; // x9
  unsigned __int64 *v8; // x11
  unsigned __int64 *v9; // x8
  unsigned __int64 v10; // x12
  unsigned __int64 v11; // x14
  unsigned __int64 v12; // x13
  unsigned __int64 v13; // x8
  unsigned __int64 **v14; // x8
  unsigned __int64 v15; // x12
  char v16; // w8

  for ( i = (unsigned __int64 *)*a1; i != a1; i = (unsigned __int64 *)*i )
  {
    v3 = (*(i - 1) + 4095) & 0xFFFFFFFFFFFFF000LL;
    *(i - 2) &= 0xFFFFFFFFFFFFF000LL;
    *(i - 1) = v3;
  }
  result = list_sort(0, a1, _mem_sort_cmp);
  v5 = (unsigned __int64 *)*a1;
  if ( (unsigned __int64 *)*a1 != a1 )
  {
    v6 = nullptr;
    v7 = 0xDEAD000000000100LL;
    do
    {
      v9 = v5 - 2;
      v8 = (unsigned __int64 *)*v5;
      if ( v6 )
      {
        v10 = *v6;
        v11 = *v9;
        v12 = v6[1] + *v6;
        if ( *v9 <= v12 )
        {
          if ( v10 >= v11 )
            v10 = *v9;
          v13 = *(v5 - 1) + v11;
          if ( v12 > v13 )
            v13 = v6[1] + *v6;
          *v6 = v10;
          v6[1] = v13 - v10;
          v14 = (unsigned __int64 **)v5[1];
          if ( *v14 == v5 && (v15 = *v5, *(unsigned __int64 **)(*v5 + 8) == v5) )
          {
            *(_QWORD *)(v15 + 8) = v14;
            *v14 = (unsigned __int64 *)v15;
          }
          else
          {
            result = _list_del_entry_valid_or_report(v5);
          }
          *v5 = v7;
          v5[1] = v7 + 34;
          v9 = v6;
        }
      }
      v5 = v8;
      v6 = v9;
    }
    while ( v8 != a1 );
    v5 = (unsigned __int64 *)*a1;
  }
  if ( v5 != a1 )
  {
    v16 = _drm_debug;
    do
    {
      if ( (v16 & 4) != 0 )
      {
        result = _drm_dev_dbg(0, 0, 0, "base: 0x%llx - size: 0x%llx\n", *(v5 - 2), *(v5 - 1));
        v16 = _drm_debug;
      }
      v5 = (unsigned __int64 *)*v5;
    }
    while ( v5 != a1 );
  }
  return result;
}
