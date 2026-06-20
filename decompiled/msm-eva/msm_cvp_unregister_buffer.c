__int64 __fastcall msm_cvp_unregister_buffer(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x0
  __int64 inst_validate; // x0
  __int64 v6; // x19
  unsigned int v7; // w0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v10; // w20

  if ( a1 && a2 && (v3 = *(_QWORD *)(a1 + 128)) != 0 )
  {
    inst_validate = cvp_get_inst_validate(v3, a1);
    if ( inst_validate )
    {
      v6 = inst_validate;
      if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
        printk(&unk_8957C, "hfi", "unregister", (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
      if ( *a2 )
        v7 = msm_cvp_unmap_buf_dsp(a1, a2);
      else
        v7 = msm_cvp_unmap_buf_wncc(a1, a2);
      v10 = v7;
      cvp_put_inst(v6);
      return v10;
    }
    else
    {
      return 4294967192LL;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_912BD, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
