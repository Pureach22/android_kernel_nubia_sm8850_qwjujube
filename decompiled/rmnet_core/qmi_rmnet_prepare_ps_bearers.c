__int64 __fastcall qmi_rmnet_prepare_ps_bearers(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v6; // x20
  __int64 v7; // x1
  __int64 *v8; // x22
  unsigned __int8 v9; // w28
  unsigned __int8 v10; // w25
  _BOOL4 v11; // w8

  result = rmnet_get_qos_pt(a1);
  if ( a2 )
  {
    v6 = result;
    if ( result )
    {
      raw_spin_lock_bh(result + 332);
      v8 = *(__int64 **)(v6 + 56);
      if ( v8 == (__int64 *)(v6 + 56) )
      {
        v10 = 0;
      }
      else
      {
        v9 = *a2;
        v10 = 0;
        do
        {
          if ( *((_DWORD *)v8 + 6) )
          {
            *((_WORD *)v8 + 16) = 0;
            *((_BYTE *)v8 + 34) = 0;
            *((_DWORD *)v8 + 11) = 0;
            *((_WORD *)v8 + 26) = 0;
            qmi_rmnet_watchdog_remove((unsigned __int8 *)v8);
            v11 = qmi_rmnet_scale_factor == 1;
            *((_DWORD *)v8 + 6) = 1;
            *((_DWORD *)v8 + 7) = v11;
          }
          else if ( v9 )
          {
            if ( a3 )
              *(_BYTE *)(a3 + v10) = *((_BYTE *)v8 + 16);
            ++v10;
            --v9;
          }
          else
          {
            printk(&unk_2D484, v7);
            v9 = 0;
          }
          v8 = (__int64 *)*v8;
        }
        while ( v8 != (__int64 *)(v6 + 56) );
      }
      *a2 = v10;
      return raw_spin_unlock_bh(v6 + 332);
    }
  }
  return result;
}
