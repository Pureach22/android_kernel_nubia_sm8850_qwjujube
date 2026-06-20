__int64 __fastcall msm_ext_disp_register_intf(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  unsigned int v4; // w3
  int v5; // w4
  _QWORD *i; // x8
  _QWORD *v7; // x20
  _DWORD *v8; // x9
  _QWORD *v9; // x0
  _QWORD *v10; // x8
  _QWORD *v11; // x2
  unsigned int v12; // w20
  void *v13; // x0
  void *v14; // x0

  if ( a1 && a2 )
  {
    v3 = *(_QWORD *)(a1 + 168);
    if ( v3 )
    {
      mutex_lock(v3 + 88);
      if ( *(_QWORD *)(a2 + 96) )
      {
        v4 = *(_DWORD *)(a2 + 4);
        v5 = *(_DWORD *)(a2 + 8);
        if ( *(_DWORD *)a2 == -1 || v4 > 1 || v5 >= 2 )
        {
          printk(&unk_6F45, "msm_ext_disp_validate_intf");
          v12 = -22;
          goto LABEL_38;
        }
        if ( *(_QWORD *)(a2 + 40)
          && *(_QWORD *)(a2 + 48)
          && *(_QWORD *)(a2 + 56)
          && *(_QWORD *)(a2 + 64)
          && *(_QWORD *)(a2 + 72)
          && *(_QWORD *)(a2 + 80)
          && *(_QWORD *)(a2 + 88) )
        {
          v7 = (_QWORD *)(v3 + 72);
          for ( i = *(_QWORD **)(v3 + 72); i != v7; i = (_QWORD *)*i )
          {
            v8 = (_DWORD *)*(i - 1);
            if ( *v8 == *(_DWORD *)a2 && v8[2] == v5 && v8[1] == v4 )
            {
              if ( v8 )
              {
                printk(&unk_73A2, "msm_ext_disp_register_intf");
                v12 = 0;
                goto LABEL_38;
              }
              break;
            }
          }
          v9 = (_QWORD *)_kmalloc_cache_noprof(_platform_driver_register, 3520, 24);
          if ( v9 )
          {
            *v9 = a2;
            v10 = v9 + 1;
            v11 = (_QWORD *)*v7;
            if ( *(_QWORD **)(*v7 + 8LL) != v7 || v10 == v7 || v11 == v10 )
            {
              _list_add_valid_or_report(v9 + 1, v3 + 72);
            }
            else
            {
              v11[1] = v10;
              v9[1] = v11;
              v9[2] = v7;
              *v7 = v10;
            }
            v12 = 0;
            *(_QWORD *)(a2 + 16) = msm_ext_disp_audio_config;
            *(_QWORD *)(a2 + 24) = msm_ext_disp_audio_notify;
          }
          else
          {
            v12 = -12;
          }
          goto LABEL_38;
        }
        v13 = &unk_6FC9;
      }
      else
      {
        v13 = &unk_71DC;
      }
      printk(v13, "msm_ext_disp_validate_intf");
      v12 = -22;
LABEL_38:
      mutex_unlock(v3 + 88);
      return v12;
    }
    v14 = &unk_705D;
  }
  else
  {
    v14 = &unk_7309;
  }
  printk(v14, "msm_ext_disp_register_intf");
  return (unsigned int)-22;
}
