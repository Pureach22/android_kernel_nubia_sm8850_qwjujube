unsigned __int64 __fastcall sde_dbg_reg_base_reg_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x25
  unsigned __int64 v8; // x19
  unsigned __int64 v9; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x9
  __int64 v12; // x0
  _QWORD *v14; // x9
  unsigned __int64 v15; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x10
  __int64 v24; // x8
  __int64 v25; // x0
  int v26; // w0
  __int64 v27; // x9
  unsigned __int64 v28; // x28
  unsigned int v29; // w19
  int v30; // w0
  int v31; // w0
  int v32; // w0
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x9
  __int64 v36; // [xsp+8h] [xbp-28h] BYREF
  __int64 v37; // [xsp+10h] [xbp-20h]
  __int64 v38; // [xsp+18h] [xbp-18h]
  __int64 v39; // [xsp+20h] [xbp-10h]
  __int64 v40; // [xsp+28h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_20;
  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
  {
    printk(&unk_21A13C, "sde_dbg_reg_base_reg_read");
    v9 = -19;
    goto LABEL_44;
  }
  if ( !a4 )
  {
LABEL_20:
    v9 = -22;
    goto LABEL_44;
  }
  mutex_lock(&unk_2942D0);
  if ( byte_2945DC != 1 )
  {
    v9 = -95;
    goto LABEL_43;
  }
  if ( *(_QWORD *)(v4 + 152) )
  {
    v8 = *(_QWORD *)(v4 + 160);
    goto LABEL_7;
  }
  v24 = *(_QWORD *)(v4 + 136);
  v38 = 0;
  v39 = 0;
  v37 = 0;
  *(_QWORD *)(v4 + 160) = (4 * v24 + 60) & 0xFFFFFFFFFFFFFFC0LL;
  v25 = _kmalloc_noprof(*(_QWORD *)(v4 + 160), 3520);
  *(_QWORD *)(v4 + 152) = v25;
  if ( !v25 )
  {
    v9 = -12;
    goto LABEL_43;
  }
  if ( (*(_BYTE *)(v4 + 128) & 3) != 0 )
  {
    v9 = -14;
    goto LABEL_43;
  }
  v26 = pm_runtime_resume_and_get(qword_2942C8);
  if ( v26 < 0 )
  {
    LODWORD(v9) = v26;
    printk(&unk_27789C, "sde_dbg_reg_base_reg_read");
    v9 = (int)v9;
    goto LABEL_43;
  }
  v27 = *(_QWORD *)(v4 + 128);
  LODWORD(v28) = 0;
  v29 = 0;
  v36 = *(_QWORD *)(v4 + 112);
  LODWORD(v37) = v27;
  do
  {
    if ( *(_QWORD *)(v4 + 136) <= (unsigned __int64)v29 )
    {
      v33 = *(_QWORD *)(v4 + 160);
      v34 = (unsigned int)v28;
      goto LABEL_38;
    }
    if ( !v29 )
    {
      v30 = scnprintf(
              *(_QWORD *)(v4 + 152) + (unsigned int)v28,
              *(_QWORD *)(v4 + 160) - (unsigned int)v28,
              "0x%08x:",
              *(unsigned int *)(v4 + 128));
LABEL_30:
      LODWORD(v28) = v30 + v28;
      goto LABEL_31;
    }
    if ( (v29 & 0xC) == 0 )
    {
      v30 = scnprintf(
              *(_QWORD *)(v4 + 152) + (unsigned int)v28,
              *(_QWORD *)(v4 + 160) - (unsigned int)v28,
              "\n0x%08x:",
              v29 + *(_DWORD *)(v4 + 128));
      goto LABEL_30;
    }
LABEL_31:
    v31 = sde_reg_read(&v36, v29);
    v29 += 4;
    v32 = scnprintf(*(_QWORD *)(v4 + 152) + (unsigned int)v28, *(_QWORD *)(v4 + 160) - (unsigned int)v28, " %08x", v31);
    v33 = *(_QWORD *)(v4 + 160);
    v28 = (unsigned int)(v32 + v28);
  }
  while ( v33 > v28 );
  v34 = v28;
LABEL_38:
  v8 = (unsigned int)scnprintf(*(_QWORD *)(v4 + 152) + v34, v33 - v34, "\n") + (unsigned int)v28;
  _pm_runtime_idle(qword_2942C8, 4);
  *(_QWORD *)(v4 + 160) = v8;
LABEL_7:
  if ( v8 <= *a4 )
  {
    v9 = 0;
  }
  else
  {
    if ( v8 - *a4 >= a3 )
      v9 = a3;
    else
      v9 = v8 - *a4;
    if ( v9 >> 31 )
    {
      __break(0x800u);
    }
    else
    {
      _check_object_size(*(_QWORD *)(v4 + 152) + *a4, v9, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v11 = a2 & ((__int64)(a2 << 8) >> 8);
      v12 = v9;
      _CF = 0x8000000000LL - v9 >= v11;
      v14 = a4;
      if ( _CF )
      {
        v15 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v20 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v20);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v15);
        v12 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
        v14 = a4;
        v21 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v23 - 4096);
        _WriteStatusReg(TTBR1_EL1, v23);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v21);
      }
      if ( !v12 )
      {
        *v14 += v9;
        goto LABEL_43;
      }
    }
    printk(&unk_27A9BA, "sde_dbg_reg_base_reg_read");
    v9 = -14;
  }
LABEL_43:
  mutex_unlock(&unk_2942D0);
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return v9;
}
