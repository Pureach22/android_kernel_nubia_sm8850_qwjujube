__int64 __fastcall regulator_proxy_consumer_add(__int64 a1, __int64 a2)
{
  __int64 v4; // x19
  int v5; // w9
  unsigned __int64 v6; // x0
  int v7; // w2
  int v8; // w0
  int v9; // w0
  int v10; // w0
  void *v11; // x2
  int v12; // w20
  const char *v14; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = nullptr;
  v15[0] = 0;
  if ( a1 && a2 )
  {
    if ( of_find_property(a2, "qcom,proxy-consumer-enable", 0)
      || of_find_property(a2, "qcom,proxy-consumer-voltage", 0)
      || of_find_property(a2, "qcom,proxy-consumer-current", 0) )
    {
      mutex_lock(&proxy_consumer_list_lock);
      v4 = _kmalloc_cache_noprof(regulator_set_load, 3520, 48);
      if ( v4 )
      {
        *(_QWORD *)(v4 + 24) = a1;
        *(_BYTE *)(v4 + 32) = of_find_property(a2, "qcom,proxy-consumer-enable", 0) != 0;
        of_property_read_variable_u32_array(a2, "qcom,proxy-consumer-current", v4 + 44, 1, 0);
        if ( (of_property_read_variable_u32_array(a2, "qcom,proxy-consumer-voltage", v15, 2, 0) & 0x80000000) == 0 )
        {
          v5 = HIDWORD(v15[0]);
          *(_DWORD *)(v4 + 36) = v15[0];
          *(_DWORD *)(v4 + 40) = v5;
        }
        v14 = "proxy";
        of_property_read_string(a2, "qcom,proxy-consumer-name", &v14);
        v6 = regulator_get(a1, v14);
        *(_QWORD *)(v4 + 16) = v6;
        if ( v6 && v6 < 0xFFFFFFFFFFFFF001LL )
        {
          v7 = *(_DWORD *)(v4 + 40);
          if ( v7 >= 1 && *(_DWORD *)(v4 + 36) <= v7 && (v8 = ((__int64 (*)(void))regulator_set_voltage)()) != 0 )
          {
            v12 = v8;
            printk(&unk_6937, "regulator_proxy_consumer_add");
          }
          else
          {
            if ( *(_DWORD *)(v4 + 44) && (v9 = regulator_set_load(*(_QWORD *)(v4 + 16)), v9 < 0) )
            {
              v12 = v9;
              printk(&unk_6A99, "regulator_proxy_consumer_add");
            }
            else
            {
              if ( *(_BYTE *)(v4 + 32) != 1 || (v10 = regulator_enable(*(_QWORD *)(v4 + 16))) == 0 )
              {
                v11 = proxy_consumer_list;
                if ( proxy_consumer_list == (_UNKNOWN *)v4
                  || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)proxy_consumer_list) != &proxy_consumer_list )
                {
                  _list_add_valid_or_report(v4, &proxy_consumer_list);
                }
                else
                {
                  *(_QWORD *)((char *)&unk_8 + (_QWORD)proxy_consumer_list) = v4;
                  *(_QWORD *)v4 = v11;
                  *(_QWORD *)(v4 + 8) = &proxy_consumer_list;
                  proxy_consumer_list = (_UNKNOWN *)v4;
                }
                goto LABEL_32;
              }
              v12 = v10;
              printk(&unk_6AC5, "regulator_proxy_consumer_add");
              regulator_set_load(*(_QWORD *)(v4 + 16));
            }
            regulator_set_voltage(*(_QWORD *)(v4 + 16), 0, 0x7FFFFFFF);
          }
          regulator_put(*(_QWORD *)(v4 + 16));
        }
        else
        {
          v12 = v6;
          printk(&unk_69DE, "regulator_proxy_consumer_add");
        }
        kfree(v4);
        v4 = v12;
      }
      else
      {
        v4 = -12;
      }
LABEL_32:
      mutex_unlock(&proxy_consumer_list_lock);
      goto LABEL_33;
    }
    v4 = 0;
  }
  else
  {
    printk(&unk_6B62, "regulator_proxy_consumer_add");
    v4 = -22;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return v4;
}
