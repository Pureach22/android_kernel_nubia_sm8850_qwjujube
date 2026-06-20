__int64 __fastcall set_ltm_roi_feature(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v3; // x8
  void (*v4)(void); // x9
  __int64 *v7; // x21
  int v8; // w1
  int v9; // w5
  unsigned int v10; // w6
  int v11; // w4
  int v12; // w5
  unsigned int v13; // w6
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v17; // x0

  if ( !a1 )
    return 4294967274LL;
  v3 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v3 >= 3 )
  {
    __break(0x5512u);
    v17 = MEMORY[0x252586C]();
    return set_ltm_vlut_feature(v17);
  }
  else
  {
    v4 = *(void (**)(void))(a1 + 8 * v3 + 616);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != 1841204718 )
        __break(0x8229u);
      v4();
      v7 = (__int64 *)*a2;
      if ( *a2 )
      {
        v8 = *((_DWORD *)a2 + 2);
        if ( v8 == 24 )
        {
          v9 = *((_DWORD *)v7 + 2);
          v10 = *((_DWORD *)a2 + 11);
          if ( v9 + *(_DWORD *)v7 > v10 )
          {
            _drm_dev_dbg(0, 0, 1, "invalid input = [%u,%u], displayh = %u\n", *(_DWORD *)v7, v9, v10);
            *((_DWORD *)v7 + 2) = 0xFFFF;
          }
          v11 = *((_DWORD *)v7 + 1);
          v12 = *((_DWORD *)v7 + 3);
          v13 = *((_DWORD *)a2 + 10);
          if ( v12 + v11 > v13 )
          {
            _drm_dev_dbg(0, 0, 1, "invalid input = [%u,%u], displayv = %u\n", v11, v12, v13);
            *((_DWORD *)v7 + 3) = 0xFFFF;
          }
          v14 = v7[2];
          v15 = *v7;
          *(_QWORD *)(a3 + 7684) = v7[1];
          *(_QWORD *)(a3 + 7692) = v14;
          *(_QWORD *)(a3 + 7676) = v15;
          return 0;
        }
        else
        {
          _drm_err("invalid size of payload len %d exp %zd\n", v8, 0x18u);
          return 0;
        }
      }
      else
      {
        *(_QWORD *)(a3 + 7684) = 0;
        *(_QWORD *)(a3 + 7692) = 0;
        *(_QWORD *)(a3 + 7676) = 0;
        return 0;
      }
    }
    else if ( (_DWORD)v3 == 1 )
    {
      return 0;
    }
    else
    {
      return 4294967274LL;
    }
  }
}
