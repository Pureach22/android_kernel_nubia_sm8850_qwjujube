__int64 __fastcall mlo_mlme_clone_sta_security(__int64 a1, __int64 a2)
{
  __int64 mlo_ctx; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  _QWORD *v14; // x8
  __int64 (*v15)(void); // x8

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  result = 16;
  if ( a2 )
  {
    if ( mlo_ctx )
    {
      v14 = *(_QWORD **)(mlo_ctx + 352);
      if ( v14 )
      {
        if ( *v14 )
        {
          if ( wlan_vdev_mlme_get_cmpt_obj(a1, v5, v6, v7, v8, v9, v10, v11, v12) )
          {
            v15 = *(__int64 (**)(void))(*(_QWORD *)(mlo_ctx + 352) + 80LL);
            if ( v15 )
            {
              if ( *((_DWORD *)v15 - 1) != -572695793 )
                __break(0x8228u);
              return v15();
            }
            else
            {
              return 0;
            }
          }
          else
          {
            return 16;
          }
        }
      }
    }
  }
  return result;
}
