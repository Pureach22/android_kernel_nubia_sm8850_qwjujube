__int64 __fastcall sde_kms_get_tvm_inclusion_mem(__int64 a1, __int64 *a2)
{
  unsigned __int64 v4; // x23
  _QWORD *v5; // x25
  _QWORD *v6; // x0
  __int64 v7; // x8
  _QWORD *v8; // x2
  __int64 v9; // x9
  _QWORD *v10; // x8
  __int64 result; // x0
  _QWORD *v12; // x8
  __int64 v13; // x9
  _QWORD *v14; // x10
  _QWORD *v15; // [xsp+8h] [xbp-18h] BYREF
  _QWORD **v16; // [xsp+10h] [xbp-10h]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = &v15;
  v16 = &v15;
  if ( *(_DWORD *)(a1 + 20124) )
  {
    v4 = 0;
    v5 = (_QWORD *)(a1 + 20136);
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( v4 == 15 )
        __break(0x5512u);
      v6 = (_QWORD *)_kmalloc_cache_noprof(wake_up_process, 3520, 32);
      if ( !v6 )
        break;
      v7 = *(v5 - 1);
      v8 = v15;
      v9 = *v5 - v7 + 1;
      *v6 = v7;
      v6[1] = v9;
      v10 = v6 + 2;
      if ( (_QWORD **)v8[1] != &v15 || v8 == v10 )
      {
        _list_add_valid_or_report(v6 + 2, &v15);
      }
      else
      {
        v8[1] = v10;
        v6[2] = v8;
        v6[3] = &v15;
        v15 = v6 + 2;
      }
      ++v4;
      v5 += 12;
      if ( v4 >= *(unsigned int *)(a1 + 20124) )
        goto LABEL_12;
    }
    msm_dss_clean_io_mem(&v15);
    result = 4294967284LL;
  }
  else
  {
LABEL_12:
    v12 = v15;
    if ( v15 == &v15 )
    {
      result = 0;
    }
    else
    {
      v13 = *a2;
      v14 = v16;
      result = 0;
      v15[1] = a2;
      *a2 = (__int64)v12;
      *v14 = v13;
      *(_QWORD *)(v13 + 8) = v14;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
