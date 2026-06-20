__int64 __fastcall qcom_channel_state_worker(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  _QWORD **v4; // x20
  _QWORD *v5; // x27
  _QWORD *v6; // t1
  __int64 v7; // x23
  __int64 v8; // x8
  _DWORD *v9; // x8
  __int64 v10; // x28
  __int64 v11; // x0
  _QWORD *v12; // x23
  const char *v13; // x24
  size_t v14; // x0
  unsigned __int64 v15; // x2
  unsigned __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x24
  const char *v19; // x25
  __int64 v20; // x0
  __int64 next_available_child; // x0
  __int64 v22; // x26
  __int64 v23; // x8
  _DWORD *v24; // x8
  const char *v25; // x22
  unsigned __int64 v26; // x2
  unsigned __int64 v27; // x0
  __int64 result; // x0
  char *s1; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v30[4]; // [xsp+10h] [xbp-30h] BYREF
  __int64 v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]

  v1 = a1 - 88;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  memset(v30, 0, sizeof(v30));
  v3 = raw_spin_lock_irqsave(a1 - 88);
  v6 = *(_QWORD **)(a1 - 104);
  v4 = (_QWORD **)(a1 - 104);
  v5 = v6;
  v7 = v3;
  if ( v6 != v4 )
  {
    _ReadStatusReg(SP_EL0);
    do
    {
      if ( !*((_DWORD *)v5 - 32) )
      {
        v8 = *(v5 - 11);
        v9 = (_DWORD *)(v8 ? v8 + 44 : *(v5 - 12) + 20LL);
        if ( ((unsigned int)(*v9 - 3) > 0xFFFFFFFD || !strcmp((const char *)*(v5 - 17), "rpm_requests"))
          && (*(_BYTE *)(v5 - 18) & 1) == 0 )
        {
          raw_spin_unlock_irqrestore(v1, v7);
          v10 = *(v5 - 20);
          v11 = _kmalloc_cache_noprof(of_property_read_string, 3520, 1000);
          v12 = (_QWORD *)v11;
          if ( v11 )
          {
            *(_QWORD *)(v11 + 992) = v10;
            *(_QWORD *)(v11 + 984) = &qcom_smd_device_ops;
            v13 = (const char *)*(v5 - 17);
            v14 = strnlen(v13, 0x20u);
            if ( v14 == -1 )
            {
LABEL_45:
              _fortify_panic(2, -1, v14 + 1);
LABEL_46:
              _fortify_panic(7, 40, v26);
LABEL_47:
              _fortify_panic(7, 88, v15);
            }
            if ( v14 == 32 )
              v15 = 32;
            else
              v15 = v14 + 1;
            if ( v15 >= 0x59 )
              goto LABEL_47;
            v16 = sized_strscpy(v12 + 114, v13);
            if ( v16 <= 0x1F )
              memset((char *)v12 + v16 + 913, 0, 31 - v16);
            v17 = 0;
            v12[120] = -1;
            v18 = *(_QWORD *)(v10 + 920);
            v19 = (const char *)*(v5 - 17);
            s1 = nullptr;
            v20 = v18;
            while ( 1 )
            {
              next_available_child = of_get_next_available_child(v20, v17);
              v22 = next_available_child;
              if ( !next_available_child
                || !(unsigned int)of_property_read_string(next_available_child, "qcom,smd-channels", &s1)
                && !strcmp(s1, v19) )
              {
                break;
              }
              v20 = v18;
              v17 = v22;
            }
            v12[93] = v22;
            v12[12] = v10;
            v12[101] = qcom_smd_release_device;
            rpmsg_register_device(v12);
          }
          v7 = raw_spin_lock_irqsave(v1);
          *((_BYTE *)v5 - 144) = 1;
        }
      }
      v5 = (_QWORD *)*v5;
    }
    while ( v5 != v4 );
    v5 = *v4;
  }
  for ( ; v5 != v4; v5 = (_QWORD *)*v5 )
  {
    if ( (unsigned int)(*((_DWORD *)v5 - 32) - 1) <= 1 )
    {
      v23 = *(v5 - 11);
      v24 = (_DWORD *)(v23 ? v23 + 44 : *(v5 - 12) + 20LL);
      if ( (unsigned int)(*v24 - 1) >= 2 )
      {
        raw_spin_unlock_irqrestore(v1, v7);
        v25 = (const char *)*(v5 - 17);
        v14 = strnlen(v25, 0x20u);
        if ( v14 == -1 )
          goto LABEL_45;
        if ( v14 == 32 )
          v26 = 32;
        else
          v26 = v14 + 1;
        if ( v26 >= 0x29 )
          goto LABEL_46;
        v27 = sized_strscpy(v30, v25);
        if ( v27 <= 0x1F )
          memset((char *)v30 + v27 + 1, 0, 31 - v27);
        v31 = -1;
        rpmsg_unregister_device(v4 - 128, v30);
        *((_BYTE *)v5 - 144) = 0;
        v7 = raw_spin_lock_irqsave(v1);
      }
    }
  }
  result = raw_spin_unlock_irqrestore(v1, v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
