__int64 __fastcall sme_set_tx_power(__int64 a1, unsigned __int8 a2, __int64 a3, int a4, unsigned int a5)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x0
  __int64 v17; // x19
  __int64 result; // x0
  __int64 v19; // [xsp+8h] [xbp-38h] BYREF
  __int64 v20; // [xsp+10h] [xbp-30h]
  __int64 v21; // [xsp+18h] [xbp-28h]
  __int64 v22; // [xsp+20h] [xbp-20h]
  __int64 v23; // [xsp+28h] [xbp-18h]
  __int64 v24; // [xsp+30h] [xbp-10h]
  __int64 v25; // [xsp+38h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  qdf_trace(52, 0x3Fu, a2, 0);
  if ( a5 != (char)a5 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: error, invalid power = %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "sme_set_tx_power",
      a5);
    goto LABEL_6;
  }
  v16 = _qdf_mem_malloc(0x14u, "sme_set_tx_power", 6491);
  if ( !v16 )
  {
    result = 2;
    goto LABEL_8;
  }
  *(_DWORD *)v16 = a3;
  *(_BYTE *)(v16 + 12) = a5;
  v17 = v16;
  *(_WORD *)(v16 + 4) = WORD2(a3);
  *(_DWORD *)(v16 + 16) = a4;
  v20 = v16;
  LODWORD(v19) = 4198;
  result = scheduler_post_message_debug(
             0x34u,
             0x36u,
             54,
             (unsigned __int16 *)&v19,
             0x1969u,
             (__int64)"sme_set_tx_power");
  if ( (_DWORD)result )
  {
    _qdf_mem_free(v17);
LABEL_6:
    result = 16;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
