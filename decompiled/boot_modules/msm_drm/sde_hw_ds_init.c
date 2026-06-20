__int64 __fastcall sde_hw_ds_init(int a1, __int64 a2, int *a3)
{
  __int64 result; // x0
  int v7; // w8
  __int64 v8; // x8
  unsigned __int64 v9; // x1
  int v10; // w10
  __int64 v11; // x9
  int v12; // w8
  __int64 v13; // x9
  __int64 (__fastcall *v14)(); // x9
  int v15; // w9
  int v16; // w9
  __int64 v17; // x19
  __int64 v18; // x19
  unsigned __int64 StatusReg; // x22
  __int64 v20; // x23
  __int64 (__fastcall *v21)(_QWORD, _QWORD, _QWORD); // x0
  int v22; // [xsp+18h] [xbp+18h]

  result = -22;
  if ( a2 && a3 )
  {
    result = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 96);
    if ( result )
    {
      while ( 1 )
      {
        v7 = a3[2210];
        if ( !v7 )
          goto LABEL_64;
        if ( a3[2216] == a1 && *((_QWORD *)a3 + 1113) )
        {
          v8 = 2212;
          goto LABEL_52;
        }
        if ( v7 == 1 )
          goto LABEL_64;
        if ( a3[2232] == a1 && *((_QWORD *)a3 + 1121) )
        {
          v8 = 2228;
          goto LABEL_52;
        }
        if ( v7 == 2 )
          goto LABEL_64;
        if ( a3[2248] == a1 && *((_QWORD *)a3 + 1129) )
        {
          v8 = 2244;
          goto LABEL_52;
        }
        if ( v7 == 3 )
          goto LABEL_64;
        if ( a3[2264] == a1 && *((_QWORD *)a3 + 1137) )
        {
          v8 = 2260;
          goto LABEL_52;
        }
        if ( v7 == 4 )
          goto LABEL_64;
        if ( a3[2280] == a1 && *((_QWORD *)a3 + 1145) )
        {
          v8 = 2276;
          goto LABEL_52;
        }
        if ( v7 == 5 )
          goto LABEL_64;
        if ( a3[2296] == a1 && *((_QWORD *)a3 + 1153) )
        {
          v8 = 2292;
          goto LABEL_52;
        }
        if ( v7 == 6 )
          goto LABEL_64;
        if ( a3[2312] == a1 && *((_QWORD *)a3 + 1161) )
        {
          v8 = 2308;
          goto LABEL_52;
        }
        if ( v7 == 7 )
          goto LABEL_64;
        if ( a3[2328] == a1 && *((_QWORD *)a3 + 1169) )
        {
          v8 = 2324;
          goto LABEL_52;
        }
        if ( v7 == 8 )
          goto LABEL_64;
        if ( a3[2344] == a1 && *((_QWORD *)a3 + 1177) )
        {
          v8 = 2340;
          goto LABEL_52;
        }
        if ( v7 == 9 )
          goto LABEL_64;
        if ( a3[2360] == a1 && *((_QWORD *)a3 + 1185) )
        {
          v8 = 2356;
          goto LABEL_52;
        }
        if ( v7 == 10 )
          goto LABEL_64;
        if ( a3[2376] == a1 && *((_QWORD *)a3 + 1193) )
        {
          v8 = 2372;
          goto LABEL_52;
        }
        if ( v7 == 11 )
          goto LABEL_64;
        if ( a3[2392] == a1 && *((_QWORD *)a3 + 1201) )
          break;
        if ( v7 == 12 )
          goto LABEL_64;
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v20 = *(_QWORD *)(StatusReg + 80);
        v21 = _kmalloc_cache_noprof;
        *(_QWORD *)(StatusReg + 80) = &sde_hw_ds_init__alloc_tag;
        result = _kmalloc_cache_noprof(v21, 3520, 96);
        *(_QWORD *)(StatusReg + 80) = v20;
        if ( !result )
          return -12;
      }
      v8 = 2388;
LABEL_52:
      v9 = (unsigned __int64)&a3[v8];
      *(_QWORD *)result = a2;
      v10 = *a3;
      v11 = *(_QWORD *)&a3[v8 + 14];
      v12 = *(_DWORD *)(v11 + 20);
      *(_DWORD *)(result + 8) = v12;
      *(_DWORD *)(result + 12) = *(_DWORD *)(v11 + 24);
      *(_DWORD *)(result + 20) = v10;
      *(_DWORD *)(result + 24) = 0x2000;
      if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
      {
LABEL_64:
        v18 = result;
        printk(&unk_213701, "sde_hw_ds_init");
        kfree(v18);
        return -22;
      }
      v13 = *(_QWORD *)(v9 + 32);
      *(_DWORD *)(result + 32) = a1;
      v22 = v13;
      v14 = sde_hw_ds_setup_opmode;
      if ( (v22 & 4) != 0 )
        v14 = sde_hw_ds_setup_opmode_v1;
      *(_QWORD *)(result + 40) = v9;
      *(_QWORD *)(result + 48) = v14;
      if ( (v22 & 8) != 0 || (v22 & 0x400000) != 0 )
        *(_QWORD *)(result + 72) = sde_hw_ds_setup_scaler3;
      v15 = a3[5];
      if ( v15 )
        *(_DWORD *)(v9 + 48) = v15;
      v16 = *(_DWORD *)(v9 + 24);
      if ( v16 )
      {
        v17 = result;
        sde_dbg_reg_register_dump_range(
          (__int64)"sde",
          (const char *)v9,
          *(_DWORD *)(v9 + 20) + v12,
          *(_DWORD *)(v9 + 20) + v12 + v16,
          *(_DWORD *)(result + 16));
        return v17;
      }
    }
    else
    {
      return -12;
    }
  }
  return result;
}
