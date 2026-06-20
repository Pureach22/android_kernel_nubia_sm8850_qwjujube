__int64 __fastcall drm_dp_mst_atomic_setup_commit(__int64 a1)
{
  __int64 v2; // x21
  _QWORD *v3; // x8
  __int64 v4; // x26
  unsigned int v5; // w20
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x20
  __int64 v9; // x27
  int v10; // w28
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x25
  __int64 v15; // x1
  unsigned int v21; // w8

  if ( *(int *)(a1 + 56) >= 1 )
  {
    v2 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      v3 = (_QWORD *)(*(_QWORD *)(a1 + 64) + 32 * v2);
      if ( *(__int64 (__fastcall ***)())(*v3 + 96LL) == drm_dp_mst_topology_state_funcs )
      {
        v4 = v3[3];
        if ( *(_DWORD *)(v4 + 24) )
        {
          v5 = _sw_hweight32();
          if ( (v5 & 0x80000000) != 0 )
          {
            *(_QWORD *)(v4 + 32) = 0;
            return 4294967284LL;
          }
          v6 = _kmalloc_noprof(8LL * v5, 3264);
          *(_QWORD *)(v4 + 32) = v6;
          if ( !v6 )
            return 4294967284LL;
          *(_QWORD *)(v4 + 40) = (int)v5;
          v7 = *(_QWORD *)(a1 + 8);
          if ( *(int *)(v7 + 860) >= 1 )
          {
            v8 = 0;
            v9 = 0;
            v10 = 0;
            while ( 2 )
            {
              v11 = *(_QWORD *)(a1 + 32);
              v12 = *(_QWORD *)(v11 + v8);
              if ( !v12 || ((*(_DWORD *)(v4 + 24) >> *(_DWORD *)(v12 + 160)) & 1) == 0 )
                goto LABEL_12;
              v13 = *(_QWORD *)(*(_QWORD *)(v11 + v8 + 24) + 320LL);
              _X0 = (unsigned int *)(v13 + 8);
              __asm { PRFM            #0x11, [X0] }
              do
                v21 = __ldxr(_X0);
              while ( __stxr(v21 + 1, _X0) );
              if ( v21 )
              {
                if ( (((v21 + 1) | v21) & 0x80000000) != 0 )
                {
                  v15 = 1;
                  goto LABEL_10;
                }
              }
              else
              {
                v15 = 2;
LABEL_10:
                refcount_warn_saturate(_X0, v15);
              }
              *(_QWORD *)(*(_QWORD *)(v4 + 32) + 8LL * v10++) = v13;
              v7 = *(_QWORD *)(a1 + 8);
LABEL_12:
              ++v9;
              v8 += 56;
              if ( v9 >= *(int *)(v7 + 860) )
                break;
              continue;
            }
          }
        }
      }
      ++v2;
    }
    while ( v2 < *(int *)(a1 + 56) );
  }
  return 0;
}
