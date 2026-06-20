unsigned __int64 __fastcall mem_buf_dev_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  size_t v3; // x20
  unsigned __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x9
  size_t v9; // x22
  unsigned __int64 v10; // x1
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x21
  int v22; // w22
  unsigned __int64 v23; // x0
  unsigned __int64 v24; // x21
  int v25; // w22
  unsigned __int64 v26; // x0
  unsigned __int64 v27; // x21
  __int64 v28; // x0
  __int64 v29; // [xsp+8h] [xbp-58h] BYREF
  __int64 v30; // [xsp+10h] [xbp-50h]
  __int64 v31; // [xsp+18h] [xbp-48h]
  __int64 v32; // [xsp+20h] [xbp-40h]
  __int64 v33; // [xsp+28h] [xbp-38h]
  __int64 v34; // [xsp+30h] [xbp-30h]
  __int64 v35; // [xsp+38h] [xbp-28h]
  __int64 v36; // [xsp+40h] [xbp-20h]
  __int64 v37; // [xsp+48h] [xbp-18h]
  unsigned int v38; // [xsp+54h] [xbp-Ch]
  __int64 v39; // [xsp+58h] [xbp-8h]

  v3 = HIWORD(a2) & 0x3FFF;
  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)v3 > 0x48 )
  {
    result = -22;
LABEL_61:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v29 = 0;
  _check_object_size(&v29, HIWORD(a2) & 0x3FFF, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v8 = a3 & ((__int64)(a3 << 8) >> 8);
  v9 = v3;
  if ( 0x8000000000LL - v3 >= v8 )
  {
    v11 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v17 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v17);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v11);
    v9 = _arch_copy_from_user(&v29, a3 & 0xFF7FFFFFFFFFFFFFLL, v3);
    v18 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v20 - 4096);
    _WriteStatusReg(TTBR1_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v18);
    if ( !v9 )
    {
LABEL_14:
      if ( (a2 & 0x40000000) == 0 )
      {
        v36 = 0;
        v37 = 0;
        v34 = 0;
        v35 = 0;
        v32 = 0;
        v33 = 0;
        v30 = 0;
        v31 = 0;
        v29 = 0;
      }
      result = -25;
      if ( a2 > -1070576382 )
      {
        if ( a2 > -1070052093 )
        {
          if ( a2 == -1070052092 )
          {
            LODWORD(result) = mem_buf_retrieve_user(&v29);
            if ( !(_DWORD)result )
              goto LABEL_58;
          }
          else
          {
            if ( a2 != -1069003520 )
              goto LABEL_61;
            if ( (mem_buf_capability & 2) == 0 )
            {
              result = -95;
              goto LABEL_61;
            }
            LODWORD(result) = mem_buf_alloc_fd(&v29);
            if ( (result & 0x80000000) == 0 )
            {
              HIDWORD(v33) = result;
              goto LABEL_58;
            }
          }
        }
        else if ( a2 == -1070576381 )
        {
          LODWORD(result) = mem_buf_lend_user(&v29);
          if ( !(_DWORD)result )
            goto LABEL_58;
        }
        else
        {
          if ( a2 != -1070576378 )
            goto LABEL_61;
          LODWORD(result) = mem_buf_lend_user(&v29);
          if ( !(_DWORD)result )
          {
LABEL_58:
            _check_object_size(&v29, v3, 1);
            if ( inline_copy_to_user(a3, &v29, v3) )
              result = -14;
            else
              result = 0;
            goto LABEL_61;
          }
        }
        result = (int)result;
        goto LABEL_61;
      }
      switch ( a2 )
      {
        case -1073197822:
          v23 = dma_buf_get((unsigned int)v29);
          v24 = v23;
          if ( v23 < 0xFFFFFFFFFFFFF001LL )
          {
            if ( (unsigned __int64)to_mem_buf_vmperm(v23) <= 0xFFFFFFFFFFFFF000LL )
            {
              v25 = 0;
              HIDWORD(v29) = mem_buf_dma_buf_exclusive_owner(v24) & 1;
            }
            else
            {
              v25 = -22;
            }
            dma_buf_put(v24);
          }
          else
          {
            v25 = v23;
          }
          if ( !v25 )
            goto LABEL_58;
          break;
        case -1072673531:
          v38 = 0;
          v26 = dma_buf_get((unsigned int)v30);
          if ( v26 < 0xFFFFFFFFFFFFF001LL )
          {
            v27 = v26;
            if ( (unsigned int)mem_buf_dma_buf_get_memparcel_hdl() )
            {
              v25 = -22;
            }
            else
            {
              v25 = 0;
              v29 = v38;
            }
            dma_buf_put(v27);
          }
          else
          {
            v25 = v26;
          }
          if ( !v25 )
            goto LABEL_58;
          break;
        case -1071624957:
          result = -22;
          if ( HIDWORD(v30) || v31 || v32 )
            goto LABEL_61;
          result = dma_buf_get((unsigned int)v30);
          if ( result < 0xFFFFFFFFFFFFF001LL )
          {
            v21 = result;
            v22 = mem_buf_reclaim();
            dma_buf_put(v21);
            LODWORD(result) = v22;
          }
          if ( (_DWORD)result )
          {
            result = (int)result;
            goto LABEL_61;
          }
          goto LABEL_58;
        default:
          goto LABEL_61;
      }
      result = v25;
      goto LABEL_61;
    }
  }
  if ( v3 - v9 <= 0x48 )
    v10 = 72 - (v3 - v9);
  else
    v10 = 0;
  if ( v10 >= v9 )
  {
    memset((char *)&v29 + v3 - v9, 0, v9);
    if ( v9 )
    {
      result = -14;
      goto LABEL_61;
    }
    goto LABEL_14;
  }
  v28 = _fortify_panic(15, v10);
  return mem_buf_lend_user(v28);
}
