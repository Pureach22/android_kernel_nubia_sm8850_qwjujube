__int64 __fastcall msm_dss_get_io_mem(__int64 a1, __int64 *a2)
{
  int string_helper; // w21
  int v4; // w0
  int v5; // w22
  unsigned int v6; // w23
  unsigned int v7; // w26
  const char *v8; // x27
  __int64 resource_byname; // x0
  __int64 *v10; // x26
  __int64 *v11; // x0
  __int64 v12; // x8
  _QWORD *v13; // x2
  _QWORD *v14; // x8
  _QWORD *v15; // x9
  _QWORD *v16; // x8
  _QWORD *v17; // x21
  _QWORD *v18; // x8
  _QWORD *v19; // x10
  __int64 result; // x0
  __int64 v21; // x9
  _QWORD *v22; // x8
  _QWORD *v23; // x21
  const char *v25; // [xsp+18h] [xbp-28h] BYREF
  const char *v26; // [xsp+20h] [xbp-20h] BYREF
  _QWORD *v27; // [xsp+28h] [xbp-18h] BYREF
  _QWORD **v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = nullptr;
  v26 = nullptr;
  v27 = &v27;
  v28 = &v27;
  string_helper = of_property_read_string_helper(*(_QWORD *)(a1 + 760), "reg-names", 0, 0, 0);
  v4 = of_property_read_string_helper(*(_QWORD *)(a1 + 760), "qcom,sde-vm-exclude-reg-names", 0, 0, 0);
  if ( string_helper < 1 )
  {
LABEL_23:
    v18 = v27;
    if ( v27 == &v27 )
    {
      result = 0;
    }
    else
    {
      v19 = v28;
      result = 0;
      v21 = *a2;
      v27[1] = a2;
      *a2 = (__int64)v18;
      *v19 = v21;
      *(_QWORD *)(v21 + 8) = v19;
    }
    goto LABEL_34;
  }
  v5 = v4;
  v6 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    of_property_read_string_helper(*(_QWORD *)(a1 + 760), "reg-names", &v26, 1, v6);
    if ( v5 >= 1 )
    {
      v7 = 0;
      while ( 1 )
      {
        of_property_read_string_helper(*(_QWORD *)(a1 + 760), "qcom,sde-vm-exclude-reg-names", &v25, 1, v7);
        v8 = v26;
        if ( !strcmp(v26, v25) )
          goto LABEL_4;
        if ( v5 == ++v7 )
          goto LABEL_11;
      }
    }
    v8 = v26;
LABEL_11:
    resource_byname = platform_get_resource_byname(a1, 512, v8);
    if ( !resource_byname )
      goto LABEL_23;
    v10 = (__int64 *)resource_byname;
    v11 = (__int64 *)_kmalloc_cache_noprof(wake_up_process, 3520, 32);
    if ( !v11 )
      break;
    v12 = *v10;
    v13 = v27;
    *v11 = *v10;
    v11[1] = v10[1] - v12 + 1;
    v14 = v11 + 2;
    if ( (_QWORD **)v13[1] != &v27 || v13 == v14 )
    {
      _list_add_valid_or_report(v11 + 2, &v27);
    }
    else
    {
      v13[1] = v14;
      v11[2] = (__int64)v13;
      v11[3] = (__int64)&v27;
      v27 = v11 + 2;
    }
LABEL_4:
    if ( string_helper == ++v6 )
      goto LABEL_23;
  }
  v15 = v27;
  if ( v27 != &v27 )
  {
    do
    {
      v17 = (_QWORD *)*v15;
      v16 = (_QWORD *)v15[1];
      if ( (_QWORD *)*v16 == v15 && (_QWORD *)v17[1] == v15 )
      {
        v17[1] = v16;
        *v16 = v17;
      }
      else
      {
        _list_del_entry_valid_or_report(v15);
      }
      *v15 = 0xDEAD000000000100LL;
      v15[1] = 0xDEAD000000000122LL;
      kfree(v15 - 2);
      v15 = v17;
    }
    while ( v17 != &v27 );
    v15 = v27;
  }
  if ( v15 != &v27 )
  {
    do
    {
      v23 = (_QWORD *)*v15;
      v22 = (_QWORD *)v15[1];
      if ( (_QWORD *)*v22 == v15 && (_QWORD *)v23[1] == v15 )
      {
        v23[1] = v22;
        *v22 = v23;
      }
      else
      {
        _list_del_entry_valid_or_report(v15);
      }
      *v15 = 0xDEAD000000000100LL;
      v15[1] = 0xDEAD000000000122LL;
      kfree(v15 - 2);
      v15 = v23;
    }
    while ( v23 != &v27 );
  }
  result = 4294967284LL;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
