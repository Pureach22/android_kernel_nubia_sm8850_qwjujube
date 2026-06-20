__int64 __fastcall cpu_hot_probe(__int64 a1)
{
  __int64 v2; // x20
  __int64 next_available_child; // x0
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 v6; // x27
  int v7; // w0
  char v8; // w8
  __int64 v9; // x25
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x28
  __int64 cpu_device; // x0
  char *v13; // x28
  size_t v14; // x0
  unsigned __int64 v15; // x2
  void *v16; // x2
  __int64 result; // x0
  char *string; // [xsp+0h] [xbp-60h] BYREF
  _QWORD v19[11]; // [xsp+8h] [xbp-58h] BYREF

  v19[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  string = nullptr;
  cpu_hot_cdev_list = &cpu_hot_cdev_list;
  off_F8 = &cpu_hot_cdev_list;
  next_available_child = of_get_next_available_child(v2, 0);
  if ( next_available_child )
  {
    v4 = next_available_child;
    while ( 1 )
    {
      v5 = devm_kmalloc(a1 + 16, 128, 3520);
      if ( !v5 )
        break;
      v6 = v5;
      *(_QWORD *)(v5 + 24) = 0;
      *(_QWORD *)(v5 + 32) = v4;
      *(_DWORD *)(v5 + 16) = -1;
      *(_WORD *)(v5 + 20) = 256;
      memset(v19, 0, 80);
      v7 = _of_parse_phandle_with_args(v4, "qcom,cpu", 0, 0, 0, v19);
      v8 = 0;
      if ( v7 )
        v9 = 0;
      else
        v9 = v19[0];
      do
      {
        v10 = (unsigned int)(-1LL << v8) & _cpu_possible_mask;
        if ( !(_DWORD)v10 )
          break;
        v11 = __clz(__rbit64(v10));
        cpu_device = get_cpu_device((unsigned int)v11);
        if ( cpu_device && *(_QWORD *)(cpu_device + 744) == v9 )
        {
          *(_DWORD *)(v6 + 16) = v11;
          goto LABEL_13;
        }
        v8 = v11 + 1;
      }
      while ( v11 < 0x1F );
      if ( *(_DWORD *)(v6 + 16) == -1 )
      {
        dev_err(a1 + 16, "Invalid CPU phandle\n");
      }
      else
      {
LABEL_13:
        if ( (unsigned int)of_property_read_string(v4, "qcom,cdev-alias", &string) )
        {
          snprintf((char *)(v6 + 40), 0x14u, "cpu-hotplug%d", *(_DWORD *)(v6 + 16));
        }
        else
        {
          v13 = string;
          v14 = strnlen(string, 0x14u);
          if ( v14 == -1 )
            goto LABEL_33;
          if ( v14 == 20 )
            v15 = 20;
          else
            v15 = v14 + 1;
          if ( v15 >= 0x15 )
          {
            _fortify_panic(7, 20);
LABEL_33:
            _fortify_panic(2, -1);
          }
          sized_strscpy(v6 + 40, v13);
        }
        *(_QWORD *)(v6 + 64) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v6 + 72) = v6 + 72;
        *(_QWORD *)(v6 + 80) = v6 + 72;
        *(_QWORD *)(v6 + 88) = cpu_hot_register_cdev;
        *(_QWORD *)(v6 + 96) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v6 + 104) = v6 + 104;
        *(_QWORD *)(v6 + 112) = v6 + 104;
        v16 = cpu_hot_cdev_list;
        *(_QWORD *)(v6 + 120) = cpu_hot_execute_cdev;
        if ( v16 == (void *)v6 || *(_UNKNOWN ***)((char *)off_8 + (_QWORD)v16) != &cpu_hot_cdev_list )
        {
          _list_add_valid_or_report(v6, &cpu_hot_cdev_list);
        }
        else
        {
          *(__int64 (__fastcall **)())((char *)off_8 + (_QWORD)v16) = (__int64 (__fastcall *)())v6;
          *(_QWORD *)v6 = v16;
          *(_QWORD *)(v6 + 8) = &cpu_hot_cdev_list;
          cpu_hot_cdev_list = (_UNKNOWN *)v6;
        }
      }
      v4 = of_get_next_available_child(v2, v4);
      if ( !v4 )
        goto LABEL_28;
    }
    result = 4294967284LL;
  }
  else
  {
LABEL_28:
    result = _cpuhp_setup_state(193, "cpu-hotplug/cdev:online", 1, cpu_hot_hp_online, 0, 0);
    if ( (result & 0x80000000) == 0 )
    {
      cpu_hp_online = result;
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
