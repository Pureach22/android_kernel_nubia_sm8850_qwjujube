__int64 __fastcall tgt_disa_encrypt_decrypt_resp(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 context; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v30; // x8
  __int64 v31; // x21
  void (__fastcall *v32)(__int64, __int64); // x22
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  qdf_trace_msg(0x5Cu, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "tgt_disa_encrypt_decrypt_resp");
  if ( a10 )
  {
    context = disa_get_context();
    if ( context )
    {
      v28 = context;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(context + 24);
        v30 = *(_QWORD *)(v28 + 32);
      }
      else
      {
        raw_spin_lock_bh(context + 24);
        v30 = *(_QWORD *)(v28 + 32) | 1LL;
        *(_QWORD *)(v28 + 32) = v30;
      }
      v32 = *(void (__fastcall **)(__int64, __int64))v28;
      v31 = *(_QWORD *)(v28 + 8);
      *(_QWORD *)v28 = 0;
      *(_QWORD *)(v28 + 8) = 0;
      *(_BYTE *)(v28 + 16) = 0;
      if ( (v30 & 1) != 0 )
      {
        *(_QWORD *)(v28 + 32) = v30 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v28 + 24);
        if ( v32 )
          goto LABEL_9;
      }
      else
      {
        raw_spin_unlock(v28 + 24);
        if ( v32 )
        {
LABEL_9:
          if ( *((_DWORD *)v32 - 1) != -1750257131 )
            __break(0x8236u);
          v32(v31, a10);
        }
      }
      qdf_trace_msg(0x5Cu, 8u, "%s: exit", v33, v34, v35, v36, v37, v38, v39, v40, "tgt_disa_encrypt_decrypt_resp");
      return 0;
    }
    qdf_trace_msg(
      0x5Cu,
      2u,
      "%s: DISA context is NULL!",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "tgt_disa_encrypt_decrypt_resp");
    return 4;
  }
  else
  {
    qdf_trace_msg(
      0x5Cu,
      2u,
      "%s: encrypt/decrypt resp is null",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "tgt_disa_encrypt_decrypt_resp");
    return 29;
  }
}
