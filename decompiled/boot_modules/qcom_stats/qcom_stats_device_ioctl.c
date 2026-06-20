__int64 __fastcall qcom_stats_device_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  _QWORD *v5; // x23
  __int64 v6; // x2
  __int64 (__fastcall *v7)(_QWORD, _QWORD); // x0
  unsigned __int64 v8; // x22
  __int64 v9; // x1
  __int64 v10; // x19
  char **v11; // x8
  __int64 v12; // x8
  __int64 v13; // x1
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v15; // x9
  int v16; // w0
  unsigned __int64 v17; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  _QWORD *v27; // x8
  int v28; // w0
  unsigned __int64 v29; // x21
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x9
  _QWORD *v33; // t2
  int v34; // w9
  unsigned __int64 v35; // x11
  unsigned __int64 v36; // x0
  unsigned __int64 v37; // x8
  unsigned __int64 v38; // x9
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x9
  unsigned __int64 v41; // x9
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x8
  unsigned __int64 v46; // x9
  int v47; // w8
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x9
  unsigned __int64 v50; // x9
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x8
  unsigned __int64 v55; // x9
  __int64 result; // x0
  unsigned __int64 v57; // x24
  __int64 v58; // x25
  int v59; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v60; // [xsp+8h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD **)(a1 + 32);
  mutex_lock(&sleep_stats_mutex);
  if ( a2 == -2146919155 )
  {
    v6 = 640;
    v7 = (__int64 (__fastcall *)(_QWORD, _QWORD))MEMORY[0xC040];
    v8 = 640;
  }
  else
  {
    v6 = 32;
    v7 = _copy_overflow;
    v8 = 32;
  }
  v10 = _kmalloc_cache_noprof(v7, 3520, v6);
  if ( v10 )
  {
    while ( 2 )
    {
      v11 = &subsystems;
      switch ( a2 )
      {
        case -2146919168:
          v11 = &off_278;
          goto LABEL_46;
        case -2146919167:
          goto LABEL_46;
        case -2146919166:
          v11 = &off_170;
          goto LABEL_46;
        case -2146919165:
          v11 = &off_188;
          goto LABEL_46;
        case -2146919164:
          v11 = &off_248;
          goto LABEL_46;
        case -2146919163:
          v11 = &off_1A0;
          goto LABEL_46;
        case -2146919162:
          v11 = &off_200;
          goto LABEL_46;
        case -2146919161:
          v11 = &off_218;
          goto LABEL_46;
        case -2146919160:
          v11 = &off_230;
          goto LABEL_46;
        case -2146919159:
          v11 = &off_260;
          goto LABEL_46;
        case -2146919158:
          if ( !*(_QWORD *)(v5[1] + 24LL) )
            goto LABEL_29;
          v12 = 8;
          goto LABEL_21;
        case -2146919157:
          if ( *(_QWORD *)(v5[1] + 24LL) <= 1u )
            goto LABEL_29;
          v12 = 24;
          goto LABEL_21;
        case -2146919156:
          if ( *(_QWORD *)(v5[1] + 24LL) <= 2u )
            goto LABEL_29;
          v12 = 40;
LABEL_21:
          v13 = *(_QWORD *)(v5[2] + v12);
          if ( v13 )
          {
            _memcpy_fromio(v10, v13, 32);
            if ( *(_QWORD *)(v10 + 8) > *(_QWORD *)(v10 + 16) )
            {
              __isb(0xFu);
              *(_QWORD *)(v10 + 24) += _ReadStatusReg(CNTVCT_EL0) - *(_QWORD *)(v10 + 8);
            }
            StatusReg = _ReadStatusReg(SP_EL0);
            if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v15 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
              v15 = a3 & ((__int64)(a3 << 8) >> 8);
            v16 = 32;
            if ( v15 <= 0x7FFFFFFFE0LL )
            {
              v17 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v23 = *(_QWORD *)(StatusReg + 8);
              _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v23);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v17);
              v16 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, v10, 32);
              v24 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v26 - 4096);
              _WriteStatusReg(TTBR1_EL1, v26);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v24);
            }
LABEL_55:
            LODWORD(v29) = v16;
            goto LABEL_67;
          }
LABEL_29:
          v5 = &unk_9000;
          v27 = (_QWORD *)drv;
          if ( *(_BYTE *)(*(_QWORD *)(drv + 8) + 35LL) == 1 )
          {
            v28 = qcom_stats_ddr_freqsync_msg();
            if ( v28 )
            {
              LODWORD(v29) = v28;
              goto LABEL_67;
            }
            while ( 1 )
            {
              v30 = ktime_get_with_offset(1);
              v27 = (_QWORD *)drv;
              if ( v30 >= *(_QWORD *)(drv + 248) )
                break;
              _const_udelay(2147500);
            }
          }
          v33 = v27;
          v31 = *v27;
          v32 = v33[1];
          v59 = 0;
          qcom_stats_fill_ddr_stats(v31 + *(_QWORD *)(v32 + 8), v10, (unsigned int *)&v59);
          if ( *(_BYTE *)(*(_QWORD *)(drv + 8) + 35LL) != 1 )
          {
            v29 = 640;
            goto LABEL_61;
          }
          if ( !v59 )
          {
            v29 = 0;
            goto LABEL_62;
          }
          v34 = 0;
          break;
        case -2146919155:
          goto LABEL_29;
        case -2146919154:
          v11 = &off_290;
          goto LABEL_46;
        case -2146919153:
          v11 = &off_2A8;
LABEL_46:
          v36 = qcom_smem_get(*((unsigned int *)v11 + 3), *((unsigned int *)v11 + 2), 0);
          if ( v36 > 0xFFFFFFFFFFFFF000LL )
          {
            LODWORD(v29) = -5;
            goto LABEL_67;
          }
          *(_DWORD *)v10 = *(_DWORD *)v36;
          *(_DWORD *)(v10 + 4) = *(_DWORD *)(v36 + 4);
          v37 = *(_QWORD *)(v36 + 8);
          *(_QWORD *)(v10 + 8) = v37;
          v38 = *(_QWORD *)(v36 + 16);
          *(_QWORD *)(v10 + 16) = v38;
          *(_QWORD *)(v10 + 24) = *(_QWORD *)(v36 + 24);
          if ( v37 > v38 )
          {
            __isb(0xFu);
            *(_QWORD *)(v10 + 24) += _ReadStatusReg(CNTVCT_EL0) - *(_QWORD *)(v10 + 8);
          }
          v39 = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(v39 + 70) & 0x20) != 0 || (v40 = a3, (*(_QWORD *)v39 & 0x4000000) != 0) )
            v40 = a3 & ((__int64)(a3 << 8) >> 8);
          v16 = 32;
          if ( v40 <= 0x7FFFFFFFE0LL )
          {
            v41 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v43 = *(_QWORD *)(v39 + 8);
            _WriteStatusReg(TTBR1_EL1, v43 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v43);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v41);
            v16 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, v10, 32);
            v44 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v46 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v46 - 4096);
            _WriteStatusReg(TTBR1_EL1, v46);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v44);
          }
          goto LABEL_55;
        default:
          printk(&unk_A189, v9);
          LODWORD(v29) = -22;
          goto LABEL_67;
      }
      while ( 1 )
      {
        v35 = 32LL * v34;
        if ( v8 <= v35 )
          break;
        if ( *(unsigned __int8 *)(v10 + v35 + 1) << 8 == 256 )
        {
          if ( v8 < (v35 | 4) )
            break;
          if ( !*(_DWORD *)(v10 + v35 + 4) )
            goto LABEL_57;
        }
        if ( v59 == ++v34 )
        {
          v34 = v59;
LABEL_57:
          if ( v34 >= 20 )
            v47 = 20;
          else
            v47 = v34;
          v29 = 32LL * v47;
LABEL_61:
          if ( v29 >= 0x281 )
          {
            _copy_overflow(640, v29);
          }
          else
          {
LABEL_62:
            _check_object_size(v10, v29, 1);
            v48 = _ReadStatusReg(SP_EL0);
            if ( (*(_BYTE *)(v48 + 70) & 0x20) != 0 || (v49 = a3, (*(_QWORD *)v48 & 0x4000000) != 0) )
              v49 = a3 & ((__int64)(a3 << 8) >> 8);
            if ( 0x8000000000LL - v29 >= v49 )
            {
              v50 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v52 = *(_QWORD *)(v48 + 8);
              _WriteStatusReg(TTBR1_EL1, v52 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v52);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v50);
              LODWORD(v29) = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, v10, v29);
              v53 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v55 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v55 - 4096);
              _WriteStatusReg(TTBR1_EL1, v55);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v53);
            }
          }
LABEL_67:
          kfree(v10);
          mutex_unlock(&sleep_stats_mutex);
          result = (int)v29;
          goto LABEL_73;
        }
      }
      __break(1u);
      v57 = _ReadStatusReg(SP_EL0);
      v58 = *(_QWORD *)(v57 + 80);
      *(_QWORD *)(v57 + 80) = &qcom_stats_device_ioctl__alloc_tag_63;
      v8 = 640;
      v10 = _kmalloc_cache_noprof(MEMORY[0xC040], 3520, 640);
      *(_QWORD *)(v57 + 80) = v58;
      if ( v10 )
        continue;
      break;
    }
  }
  mutex_unlock(&sleep_stats_mutex);
  result = -12;
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
