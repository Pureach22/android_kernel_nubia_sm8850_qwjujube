__int64 __fastcall cvp_dsp_rpmsg_callback(__int64 a1, unsigned int *a2, int a3)
{
  unsigned int v3; // w5
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x11
  __int64 v7; // x8
  int *v8; // x0
  int v9; // w9
  __int64 v10; // x5
  int *v11; // x0
  size_t v12; // x2
  int v13; // w8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  int v17; // w19
  unsigned int *v18; // x21
  unsigned __int64 v20; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v22; // x8

  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
  {
    v17 = a3;
    v18 = a2;
    printk(&unk_928B7, "dsp", "cvp_dsp_rpmsg_callback", *a2);
    a2 = v18;
    a3 = v17;
  }
  v3 = *a2;
  if ( a3 != 28 || v3 > 7 )
  {
    if ( v3 > 0x19 || a3 != 1336 && a3 != 548 )
    {
      v13 = msm_cvp_debug_out;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_8B7C0, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        v13 = msm_cvp_debug_out;
        if ( (msm_cvp_debug & 1) == 0 )
          return 0;
      }
      else if ( (msm_cvp_debug & 1) == 0 )
      {
        return 0;
      }
      if ( !v13 )
      {
        v14 = _ReadStatusReg(SP_EL0);
        printk(&unk_928EE, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
      }
      return 0;
    }
    if ( (_DWORD)qword_6C7A8 == -1159857458 )
    {
      v9 = a2[2];
      v10 = HIDWORD(*(_QWORD *)a2);
      qword_6C7A8 = *(_QWORD *)a2;
      dword_6C7B0 = v9;
      if ( a3 != 548 || (_DWORD)v10 )
      {
        if ( a3 != 1336 || (_DWORD)v10 != 1 )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v20 = _ReadStatusReg(SP_EL0);
            printk(&unk_866DA, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
          }
          return 0;
        }
        v11 = &dword_6C9D8;
        v12 = 1336;
      }
      else
      {
        v11 = &dword_6C7B4;
        v12 = 548;
      }
      memcpy(v11, a2, v12);
      v8 = &dword_6C788;
      goto LABEL_34;
    }
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v22 = _ReadStatusReg(SP_EL0);
      printk(&unk_8C1D0, *(unsigned int *)(v22 + 1800), *(unsigned int *)(v22 + 1804), &unk_8E7CE);
    }
LABEL_27:
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v16 = _ReadStatusReg(SP_EL0);
      printk(&unk_92919, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
    }
    return 0;
  }
  if ( (_DWORD)qword_6CF10 != v3 )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v15 = _ReadStatusReg(SP_EL0);
      printk(&unk_87CCD, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
    }
    goto LABEL_27;
  }
  v4 = *(_QWORD *)a2;
  v5 = *((_QWORD *)a2 + 1);
  v6 = *((_QWORD *)a2 + 2);
  dword_6CF28 = a2[6];
  qword_6CF18 = v5;
  qword_6CF20 = v6;
  qword_6CF10 = v4;
  v7 = *a2;
  if ( (unsigned int)v7 < 0xA )
  {
    v8 = (int *)((char *)&gfa_cv + 32 * v7 + 184);
LABEL_34:
    complete(v8);
    return 0;
  }
  __break(0x5512u);
  return cvp_unblocked_ioctl();
}
