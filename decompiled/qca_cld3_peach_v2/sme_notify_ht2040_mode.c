__int64 __fastcall sme_notify_ht2040_mode(__int64 a1, __int64 a2, unsigned __int8 a3, unsigned __int8 a4)
{
  unsigned int *v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int *v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  __int64 v25; // [xsp+0h] [xbp-40h] BYREF
  unsigned int *v26; // [xsp+8h] [xbp-38h]
  __int64 v27; // [xsp+10h] [xbp-30h]
  __int64 v28; // [xsp+18h] [xbp-28h]
  __int64 v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+28h] [xbp-18h]
  __int64 v31; // [xsp+30h] [xbp-10h] BYREF
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v31) = a2;
  WORD2(v31) = WORD2(a2);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = nullptr;
  if ( !a1 )
  {
LABEL_9:
    result = 16;
    goto LABEL_10;
  }
  v6 = (unsigned int *)_qdf_mem_malloc(0xCu, "sme_notify_ht2040_mode", 8012);
  if ( v6 )
  {
    v15 = v6;
    if ( (unsigned __int8)(a4 - 1) >= 3u )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Invalid OP mode %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "sme_notify_ht2040_mode",
        a4,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32);
    }
    else
    {
      *v6 = dword_B091B4[(unsigned __int8)(a4 - 1)];
      qdf_mem_copy((char *)v6 + 6, &v31, 6u);
      *((_WORD *)v15 + 2) = a3;
      LODWORD(v25) = 4263;
      v26 = v15;
      if ( !(unsigned int)scheduler_post_message_debug(
                            0x34u,
                            0x36u,
                            54,
                            (unsigned __int16 *)&v25,
                            0x1F6Au,
                            (__int64)"sme_notify_ht2040_mode") )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: vdev %d OP mode chwidth: %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "sme_notify_ht2040_mode",
          a3,
          *v15);
        result = 0;
        goto LABEL_10;
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post WMA_UPDATE_OP_MODE message to WMA",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sme_notify_ht2040_mode");
    }
    _qdf_mem_free((__int64)v15);
    goto LABEL_9;
  }
  result = 2;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
