__int64 __fastcall sde_connector_update_dimming_bl_lut(__int64 result, __int64 a2)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x19
  __int64 v4; // x21
  __int64 v6; // x23
  __int64 v7; // x2
  _DWORD *v8; // x8
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  if ( result )
  {
    if ( *(_DWORD *)(result + 2736) == 16 )
    {
      v2 = (_QWORD *)(result + 2760);
      if ( *(_BYTE *)(result + 5128) == 1 )
        v2 = (_QWORD *)*v2;
      v3 = (_QWORD *)*v2;
      if ( *v2 )
      {
        if ( !v3[33] )
        {
          printk(&unk_227B42, "_sde_connector_update_dimming_bl_lut");
          result = 4294967274LL;
          goto LABEL_12;
        }
        v4 = result;
        if ( (msm_property_is_dirty(result + 3312, a2 + 448, 8) & 1) == 0 )
        {
          result = 4294967235LL;
          goto LABEL_12;
        }
        v6 = v3[33];
        *(_QWORD *)(v6 + 1520) = msm_property_get_blob(v4 + 3312, a2 + 448, v9);
        v7 = *(unsigned int *)(v6 + 1496);
        v8 = *(_DWORD **)(v4 + 2968);
        if ( *(v8 - 1) != 1064465684 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64))v8)(v4, v3, v7);
        if ( !(_DWORD)result )
        {
          *(_DWORD *)(v4 + 4536) = 0;
          goto LABEL_12;
        }
      }
    }
    result = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
