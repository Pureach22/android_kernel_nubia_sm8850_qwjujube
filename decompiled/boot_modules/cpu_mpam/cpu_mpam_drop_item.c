__int64 __fastcall cpu_mpam_drop_item(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x20
  __int64 v4; // x21
  __int64 lock; // x0
  _QWORD *i; // x9
  __int64 v7; // x12
  _QWORD *v8; // x11
  _QWORD *v9; // x13
  _BYTE *v10; // x13
  _QWORD *v11; // x8
  __int64 v12; // x24
  __int64 v13; // x25
  __int64 v14; // x21
  __int64 v15; // x24
  __int64 result; // x0
  __int64 v17; // [xsp+0h] [xbp-20h] BYREF
  int v18; // [xsp+8h] [xbp-18h]
  int v19; // [xsp+Ch] [xbp-14h]
  __int64 v20; // [xsp+10h] [xbp-10h]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int *)(a2 + 136);
  v4 = *(unsigned int *)(a2 + 140);
  if ( (_DWORD)v3 )
  {
    lock = _rcu_read_lock();
    for ( i = (_QWORD *)init_task[199]; i - 199 != init_task; i = (_QWORD *)*i )
    {
      v7 = i[100];
      v9 = (_QWORD *)(v7 + 16);
      v8 = *(_QWORD **)(v7 + 16);
      while ( v8 != v9 )
      {
        if ( v8 - 247 == init_task )
          v10 = &vendor_data_pad;
        else
          v10 = v8 + 401;
        if ( (_DWORD)v3 == (unsigned __int8)v10[385] )
        {
          v10[385] = 0;
          v7 = i[100];
        }
        v8 = (_QWORD *)*v8;
        v9 = (_QWORD *)(v7 + 16);
      }
    }
    _rcu_read_unlock(lock);
  }
  *(_QWORD *)(part_id_free_bitmap + ((v3 >> 3) & 0x1FFFFFF8)) &= ~(1LL << v3);
  if ( (_DWORD)v4 != 0x7FFFFFFF )
  {
    if ( (unsigned int)v4 >= 0xC )
    {
      __break(0x5512u);
      JUMPOUT(0x6A80);
    }
    v11 = (_QWORD *)monitor_free_bitmap;
    *((_DWORD *)&monitor_enabled + v4) = 0x7FFFFFFF;
    *v11 &= ~(1LL << v4);
    v18 = v4;
    v19 = 2;
    v20 = 0;
    if ( mpam_msc_cnt > 0 )
    {
      v12 = 0;
      v13 = 0;
      v17 = 0;
      do
      {
        LODWORD(v17) = *(_DWORD *)(mpam_mscs + v12);
        qcom_mpam_config_monitor(&v17);
        ++v13;
        v12 += 16;
      }
      while ( v13 < mpam_msc_cnt );
      v20 = 0;
      v18 = v4;
      v19 = 1;
      if ( mpam_msc_cnt >= 1 )
      {
        v14 = 0;
        v15 = 0;
        v17 = 0;
        do
        {
          LODWORD(v17) = *(_DWORD *)(mpam_mscs + v14);
          qcom_mpam_config_monitor(&v17);
          ++v15;
          v14 += 16;
        }
        while ( v15 < mpam_msc_cnt );
      }
    }
  }
  ((void (__fastcall *)(_QWORD))cpu_mpam_reset_param)((unsigned int)v3);
  result = config_item_put(a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
