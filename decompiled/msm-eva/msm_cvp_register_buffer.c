__int64 __fastcall msm_cvp_register_buffer(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x0
  __int64 inst_validate; // x0
  __int64 v6; // x9
  __int64 v7; // x22
  unsigned int v8; // w0
  __int64 result; // x0
  unsigned __int64 v10; // x8
  unsigned int v11; // w19
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x19
  __int64 v14; // x22

  if ( a1 && a2 && (v3 = *(_QWORD *)(a1 + 128)) != 0 )
  {
    inst_validate = cvp_get_inst_validate(v3, a1);
    if ( inst_validate )
    {
      v6 = *(_QWORD *)(a1 + 320);
      if ( v6 )
      {
        if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
        {
          v14 = inst_validate;
          printk(&unk_8957C, "hfi", "register", HIDWORD(v6) ^ (unsigned int)v6);
          inst_validate = v14;
        }
        v7 = inst_validate;
        if ( *a2 )
          v8 = msm_cvp_map_buf_dsp(a1, a2);
        else
          v8 = msm_cvp_map_buf_wncc(a1, a2);
        v11 = v8;
        inst_validate = v7;
        if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_9713E, "dsp", "msm_cvp_register_buffer", (unsigned int)a2[2]);
          inst_validate = v7;
        }
      }
      else
      {
        v11 = -22;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          v13 = inst_validate;
          printk(&unk_86178, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          inst_validate = v13;
          v11 = -22;
        }
      }
      cvp_put_inst(inst_validate);
      return v11;
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
      v10 = _ReadStatusReg(SP_EL0);
      printk(&unk_912BD, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
