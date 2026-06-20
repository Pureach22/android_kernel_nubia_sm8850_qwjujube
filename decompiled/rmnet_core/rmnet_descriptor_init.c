__int64 __fastcall rmnet_descriptor_init(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x19
  int v4; // w21
  _QWORD *v5; // x0
  _QWORD *v6; // x1

  *(_DWORD *)(a1 + 2800) = 0;
  v2 = (_QWORD *)_kmalloc_cache_noprof(nla_put, 2336, 24);
  v3 = v2;
  if ( v2 )
  {
    v4 = 64;
    *v2 = v2;
    _ReadStatusReg(SP_EL0);
    v2[1] = v2;
    *(_QWORD *)(a1 + 2808) = v2;
    while ( 1 )
    {
      v5 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 88);
      if ( !v5 )
        break;
      *v5 = v5;
      v5[1] = v5;
      v5[2] = v5 + 2;
      v5[3] = v5 + 2;
      v6 = (_QWORD *)v3[1];
      if ( v5 == v3 || v6 == v5 || (_QWORD *)*v6 != v3 )
      {
        _list_add_valid_or_report(v5, v6, v3);
      }
      else
      {
        v3[1] = v5;
        *v5 = v3;
        v5[1] = v6;
        *v6 = v5;
      }
      --v4;
      ++*((_DWORD *)v3 + 4);
      if ( !v4 )
        return 0;
    }
  }
  return 4294967284LL;
}
