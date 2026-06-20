__int64 __fastcall thermal_pause_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 next_available_child; // x0
  __int64 v3; // x22
  __int64 v5; // x26
  __int64 v6; // x0
  __int64 v7; // x27
  char *v8; // x26
  size_t v9; // x0
  unsigned __int64 v10; // x2
  unsigned __int64 v11; // x8
  void *v12; // x2
  unsigned __int64 v18; // x9
  __int64 v19; // x19
  char v20; // w8
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x27
  __int64 cpu_device; // x0
  __int64 v24; // x8
  __int64 result; // x0
  char *string; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v28[7]; // [xsp+10h] [xbp-50h] BYREF
  __int64 v29; // [xsp+48h] [xbp-18h]
  unsigned __int64 v30[2]; // [xsp+50h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 760);
  string = nullptr;
  v29 = 0;
  memset(v28, 0, sizeof(v28));
  v30[0] = 0;
  thermal_pause_cdev_list = &thermal_pause_cdev_list;
  off_180 = &thermal_pause_cdev_list;
  cpus_in_max_cooling_level = 0;
  next_available_child = of_get_next_available_child(v1, 0);
  if ( next_available_child )
  {
    v3 = next_available_child;
    _X23 = v30;
    do
    {
      v30[0] = 0;
      of_phandle_iterator_init(v28, v3, "qcom,cpus", 0, 0);
      v5 = 0;
      if ( !(unsigned int)of_phandle_iterator_next(v28) )
      {
        v5 = 0;
        do
        {
          v19 = v29;
          v20 = 0;
          do
          {
            v21 = (unsigned int)(-1LL << v20) & _cpu_possible_mask;
            if ( !(_DWORD)v21 )
              break;
            v22 = __clz(__rbit64(v21));
            cpu_device = get_cpu_device((unsigned int)v22);
            if ( cpu_device && *(_QWORD *)(cpu_device + 744) == v19 )
            {
              v24 = 1LL << v22;
              __asm { PRFM            #0x11, [X23] }
              do
                v18 = __ldxr(v30);
              while ( __stxr(v18 | v24, v30) );
              v5 |= v24;
              break;
            }
            v20 = v22 + 1;
          }
          while ( v22 < 0x1F );
        }
        while ( !(unsigned int)of_phandle_iterator_next(v28) );
      }
      if ( LODWORD(v30[0]) )
      {
        v6 = devm_kmalloc(a1 + 16, 136, 3520);
        if ( !v6 )
        {
          result = 4294967284LL;
          goto LABEL_32;
        }
        v7 = v6;
        if ( (unsigned int)of_property_read_string(v3, "qcom,cdev-alias", &string) )
        {
          snprintf((char *)(v7 + 48), 0x14u, "thermal-pause-%lX", v5);
        }
        else
        {
          v8 = string;
          v9 = strnlen(string, 0x14u);
          if ( v9 == -1 )
            goto LABEL_34;
          if ( v9 == 20 )
            v10 = 20;
          else
            v10 = v9 + 1;
          if ( v10 >= 0x15 )
          {
            _fortify_panic(7, 20);
LABEL_34:
            _fortify_panic(2, -1);
          }
          sized_strscpy(v7 + 48, v8);
        }
        v11 = v30[0];
        *(_DWORD *)(v7 + 24) = 0;
        *(_QWORD *)(v7 + 32) = 0;
        *(_QWORD *)(v7 + 40) = v3;
        *(_QWORD *)(v7 + 16) = v11;
        *(_QWORD *)(v7 + 72) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v7 + 80) = v7 + 80;
        *(_QWORD *)(v7 + 88) = v7 + 80;
        *(_QWORD *)(v7 + 96) = thermal_pause_register_cdev;
        *(_QWORD *)(v7 + 104) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v7 + 112) = v7 + 112;
        *(_QWORD *)(v7 + 120) = v7 + 112;
        v12 = thermal_pause_cdev_list;
        *(_QWORD *)(v7 + 128) = thermal_pause_update_work;
        if ( v12 == (void *)v7 || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)v12) != &thermal_pause_cdev_list )
        {
          _list_add_valid_or_report(v7, &thermal_pause_cdev_list);
        }
        else
        {
          *(_QWORD *)((char *)&unk_8 + (_QWORD)v12) = v7;
          *(_QWORD *)v7 = v12;
          *(_QWORD *)(v7 + 8) = &thermal_pause_cdev_list;
          thermal_pause_cdev_list = (_UNKNOWN *)v7;
        }
      }
      v3 = of_get_next_available_child(v1, v3);
    }
    while ( v3 );
  }
  result = _cpuhp_setup_state(193, "thermal-pause/cdev:online", 1, thermal_pause_hp_online, 0, 0);
  if ( (result & 0x80000000) == 0 )
  {
    cpu_hp_online = result;
    result = 0;
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
