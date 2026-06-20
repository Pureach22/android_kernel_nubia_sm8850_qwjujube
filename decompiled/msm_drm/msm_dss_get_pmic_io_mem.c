__int64 __fastcall msm_dss_get_pmic_io_mem(__int64 a1, __int64 *a2)
{
  _QWORD *v4; // x19
  __int64 property; // x23
  __int64 v6; // x0
  __int64 v7; // x24
  unsigned int v8; // w20
  _QWORD *v9; // x0
  _QWORD *v10; // x2
  __int64 v11; // x9
  _QWORD *v12; // x8
  _QWORD *v13; // x9
  _QWORD *v14; // x8
  _QWORD *v15; // x23
  _QWORD *v16; // x8
  __int64 v17; // x9
  _QWORD *v18; // x10
  unsigned int v20; // [xsp+14h] [xbp-1Ch] BYREF
  _QWORD *v21; // [xsp+18h] [xbp-18h] BYREF
  _QWORD **v22; // [xsp+20h] [xbp-10h]
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = &v21;
  v22 = &v21;
  v4 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 96);
  if ( v4 )
  {
    property = of_find_property(*(_QWORD *)(a1 + 760), "qcom,pmic-arb-address", 0);
    v6 = of_prop_next_u32(property, 0, &v20);
    if ( v6 )
    {
      v7 = v6;
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v8 = spmi_pmic_arb_map_address(a1 + 16, v20, v4);
        if ( (v8 & 0x80000000) != 0 )
          break;
        v9 = (_QWORD *)_kmalloc_cache_noprof(wake_up_process, 3520, 32);
        if ( !v9 )
        {
          v8 = -12;
          goto LABEL_13;
        }
        v10 = v21;
        v11 = v4[1] - *v4 + 1LL;
        *v9 = *v4;
        v9[1] = v11;
        v12 = v9 + 2;
        if ( (_QWORD **)v10[1] != &v21 || v10 == v12 )
        {
          _list_add_valid_or_report(v9 + 2, &v21);
        }
        else
        {
          v10[1] = v12;
          v9[2] = v10;
          v9[3] = &v21;
          v21 = v9 + 2;
        }
        v7 = of_prop_next_u32(property, v7, &v20);
        if ( !v7 )
          goto LABEL_21;
      }
      printk(&unk_212F0D, "msm_dss_get_pmic_io_mem");
LABEL_13:
      v13 = v21;
      if ( v21 != &v21 )
      {
        do
        {
          v15 = (_QWORD *)*v13;
          v14 = (_QWORD *)v13[1];
          if ( (_QWORD *)*v14 == v13 && (_QWORD *)v15[1] == v13 )
          {
            v15[1] = v14;
            *v14 = v15;
          }
          else
          {
            _list_del_entry_valid_or_report(v13);
          }
          *v13 = 0xDEAD000000000100LL;
          v13[1] = 0xDEAD000000000122LL;
          kfree(v13 - 2);
          v13 = v15;
        }
        while ( v15 != &v21 );
      }
    }
    else
    {
      v8 = 0;
LABEL_21:
      v16 = v21;
      if ( v21 != &v21 )
      {
        v17 = *a2;
        v18 = v22;
        v21[1] = a2;
        *a2 = (__int64)v16;
        *v18 = v17;
        *(_QWORD *)(v17 + 8) = v18;
      }
    }
    kfree(v4);
  }
  else
  {
    v8 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
