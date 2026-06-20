__int64 __fastcall reg_modify_max_bw_for_240mhz_5g_chans(__int64 *a1, __int64 a2)
{
  unsigned int v3; // w23
  __int64 bonded_chan_entry; // x0
  __int64 v6; // x21
  unsigned int v7; // w22
  int v8; // w24
  unsigned __int16 *v9; // x19
  __int64 result; // x0
  _DWORD *v11; // x8
  int v12; // w9
  _WORD *i; // x8

  v3 = *((unsigned __int16 *)a1 + 26);
  bonded_chan_entry = reg_get_bonded_chan_entry(5500, 7, 0);
  v6 = *a1;
  v7 = *((unsigned __int8 *)a1 + 13);
  v8 = *((_DWORD *)a1 + 11);
  v9 = (unsigned __int16 *)bonded_chan_entry;
  result = reg_get_psoc_tx_ops(v6);
  if ( result && (unsigned __int16)v8 >= 0xA1u )
  {
    v11 = *(_DWORD **)(result + 184);
    if ( *(v11 - 1) != -79185541 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD))v11)(v6, v7);
    if ( (result & 1) != 0 )
    {
      if ( v3 )
      {
        v12 = 0;
        for ( i = (_WORD *)(a2 + 4);
              !v9
           || *v9 < (unsigned int)(unsigned __int16)*(i - 2)
           || v9[1] > (unsigned int)(unsigned __int16)*(i - 1)
           || (unsigned __int16)*i < 0xA1u;
              i += 7 )
        {
          if ( ++v12 >= v3 )
            return result;
        }
        *i = 320;
      }
    }
  }
  return result;
}
