__int64 __fastcall venus_hfi_queue_internal_buffer(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int hfi_port_from_buffer_type; // w0
  __int64 v8; // x21
  unsigned int v9; // w20
  int v10; // w22
  unsigned int v11; // w19
  __int64 result; // x0
  _QWORD v13[9]; // [xsp+8h] [xbp-48h] BYREF

  v13[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v13, 0, 64);
  if ( !a2 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8BE9D, "err ", a1 + 340, "venus_hfi_queue_internal_buffer", a5);
    goto LABEL_7;
  }
  if ( (unsigned int)get_hfi_buffer(a1, a2, (__int64)v13) )
  {
LABEL_7:
    result = 4294967274LL;
    goto LABEL_8;
  }
  hfi_port_from_buffer_type = get_hfi_port_from_buffer_type(a1, *(_DWORD *)(a2 + 24));
  v8 = *(_QWORD *)(a1 + 320);
  v9 = *(_DWORD *)(a1 + 332);
  v10 = hfi_port_from_buffer_type;
  core_lock(v8);
  v11 = venus_hfi_session_command_locked(
          a1,
          0x1000009u,
          1,
          v10,
          v9,
          5,
          v13,
          0x40u,
          (__int64)"venus_hfi_queue_internal_buffer");
  core_unlock(v8);
  result = v11;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
