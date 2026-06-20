__int64 __fastcall venus_hfi_release_buffer(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int v7; // w1
  int hfi_port_from_buffer_type; // w0
  __int64 v9; // x21
  unsigned int v10; // w20
  int v11; // w22
  unsigned int v12; // w19
  __int64 result; // x0
  _QWORD v14[5]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v15; // [xsp+30h] [xbp-20h]
  __int64 v16; // [xsp+38h] [xbp-18h]
  __int64 v17; // [xsp+40h] [xbp-10h]
  __int64 v18; // [xsp+48h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17 = 0;
  v15 = 0;
  memset(v14, 0, sizeof(v14));
  if ( !a2 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8BE9D, "err ", a1 + 340, "venus_hfi_release_buffer", a5);
    goto LABEL_7;
  }
  if ( (unsigned int)get_hfi_buffer(a1, a2, (__int64)v14) )
  {
LABEL_7:
    result = 4294967274LL;
    goto LABEL_8;
  }
  v7 = *(_DWORD *)(a2 + 24);
  LODWORD(v15) = v15 | 1;
  hfi_port_from_buffer_type = get_hfi_port_from_buffer_type(a1, v7);
  v9 = *(_QWORD *)(a1 + 320);
  v10 = *(_DWORD *)(a1 + 332);
  v11 = hfi_port_from_buffer_type;
  core_lock(v9);
  v12 = venus_hfi_session_command_locked(
          a1,
          0x1000009u,
          3,
          v11,
          v10,
          5,
          v14,
          0x40u,
          (__int64)"venus_hfi_release_buffer");
  core_unlock(v9);
  result = v12;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
