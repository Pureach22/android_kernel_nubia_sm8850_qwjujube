__int64 __fastcall sde_connector_handle_panel_id(__int64 a1, __int64 a2, __int64 a3, int a4, int a5)
{
  __int64 v6; // x0
  _DWORD *v7; // x8
  __int64 *v8; // x9
  __int64 v9; // x3
  __int64 result; // x0
  _BYTE v11[8]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    if ( (a4 & a5) != 0xFFFFFFFFLL )
    {
      v11[3] = a4;
      v11[0] = HIBYTE(a4);
      v11[2] = BYTE1(a4);
      v11[6] = BYTE1(a5);
      v11[7] = a5;
      v11[1] = BYTE2(a4);
      v11[4] = HIBYTE(a5);
      v11[5] = BYTE2(a5);
      msm_property_set_blob(a3 + 3312, a3 + 4264, v11, 8, 7);
      v6 = raw_spin_lock_irqsave(a3 + 4352);
      *(_QWORD *)(a3 + 4336) = 0;
      *(_QWORD *)(a3 + 4344) = a3;
      raw_spin_unlock_irqrestore(a3 + 4352, v6);
      v7 = *(_DWORD **)(a3 + 2960);
      if ( v7 )
      {
        v8 = *(__int64 **)(a3 + 2760);
        if ( v8 )
        {
          if ( *(_DWORD *)(a3 + 2736) == 16 )
          {
            if ( !*(_BYTE *)(a3 + 5128) )
              v8 = (__int64 *)(a3 + 2760);
            v9 = *v8;
          }
          else
          {
            v9 = 0;
          }
          if ( *(v7 - 1) != -1461547397 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v7)(a3, 4, 0, v9);
        }
      }
    }
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
