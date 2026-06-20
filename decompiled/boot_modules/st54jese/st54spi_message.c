__int64 __fastcall st54spi_message(__int64 a1, char *a2, unsigned int a3)
{
  __int64 *v3; // x21
  unsigned __int64 v5; // x25
  __int64 v6; // x20
  int v7; // w19
  unsigned __int64 v8; // x28
  unsigned int v9; // w12
  unsigned int v10; // w23
  unsigned int v11; // w27
  __int64 v12; // x14
  char *v13; // x15
  unsigned int *v14; // x24
  __int64 v15; // x8
  __int64 v16; // x10
  unsigned __int64 v17; // x9
  size_t v18; // x25
  unsigned int v19; // w19
  unsigned int v20; // w27
  __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned int v23; // w10
  __int64 *v24; // x1
  __int64 *v25; // x0
  __int64 v26; // x23
  int v27; // w0
  int v28; // w8
  unsigned int v29; // w23
  int v30; // w24
  unsigned __int64 v31; // x25
  __int64 v32; // x22
  unsigned int *v33; // x19
  __int64 v34; // x23
  unsigned __int64 v35; // x8
  unsigned __int64 v41; // x9
  __int64 v42; // x0
  unsigned __int64 v43; // x8
  unsigned __int64 v45; // x9
  unsigned __int64 v46; // x19
  __int64 v47; // x23
  char *v49; // [xsp+8h] [xbp-E8h]
  int v50; // [xsp+14h] [xbp-DCh]
  unsigned __int64 v51; // [xsp+18h] [xbp-D8h]
  __int64 v52; // [xsp+20h] [xbp-D0h]
  unsigned __int64 StatusReg; // [xsp+30h] [xbp-C0h]
  __int64 v55; // [xsp+38h] [xbp-B8h]
  int v56; // [xsp+44h] [xbp-ACh]
  unsigned __int64 v57; // [xsp+48h] [xbp-A8h]
  __int64 v58; // [xsp+50h] [xbp-A0h] BYREF
  __int64 *v59; // [xsp+58h] [xbp-98h]
  __int64 v60; // [xsp+60h] [xbp-90h]
  __int64 v61; // [xsp+68h] [xbp-88h]
  __int64 v62; // [xsp+70h] [xbp-80h]
  __int64 v63; // [xsp+78h] [xbp-78h]
  __int64 v64; // [xsp+80h] [xbp-70h]
  __int64 v65; // [xsp+88h] [xbp-68h]
  __int64 v66; // [xsp+90h] [xbp-60h]
  __int64 v67; // [xsp+98h] [xbp-58h]
  __int64 v68; // [xsp+A0h] [xbp-50h]
  _QWORD v69[5]; // [xsp+A8h] [xbp-48h] BYREF
  _QWORD v70[4]; // [xsp+D0h] [xbp-20h] BYREF

  LODWORD(v3) = a3;
  v70[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v69[2] = 0;
  v68 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = (__int64)&v58;
  v59 = &v58;
  v69[0] = v69;
  v69[1] = v69;
  v5 = 136LL * a3;
  v6 = _kmalloc_noprof(v5, 3520);
  if ( v6 )
  {
    while ( 1 )
    {
      v50 = (int)v3;
      v49 = a2;
      if ( !(_DWORD)v3 )
        break;
      v7 = (int)v3;
      v8 = 0;
      v9 = 0;
      v10 = 0;
      v11 = 0;
      v13 = *(char **)(a1 + 96);
      v12 = *(_QWORD *)(a1 + 104);
      v14 = (unsigned int *)(a2 + 16);
      v3 = &v58;
      a2 = (char *)&unk_0;
      StatusReg = _ReadStatusReg(SP_EL0);
      v51 = v5;
      v52 = v6;
      while ( v5 > v8 + 16 )
      {
        v15 = *v14;
        v11 += v15;
        *(_DWORD *)(v6 + v8 + 16) = v15;
        if ( ((v11 | (unsigned int)v15) & 0x80000000) != 0 )
          goto LABEL_52;
        if ( *((_QWORD *)v14 - 1) )
        {
          v9 += v15;
          if ( v9 > bufsiz )
            goto LABEL_52;
          if ( v5 <= v8 + 8 )
            break;
          v16 = *v14;
          *(_QWORD *)(v6 + v8 + 8) = v12;
          v17 = *((_QWORD *)v14 - 1);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (*(_QWORD *)StatusReg & 0x4000000) != 0 )
            v17 &= (__int64)(v17 << 8) >> 8;
          if ( 0x8000000000LL - v16 < v17 )
            goto LABEL_56;
          v12 += v15;
        }
        if ( *((_QWORD *)v14 - 2) )
        {
          v10 += v15;
          if ( v10 > bufsiz )
          {
LABEL_52:
            v29 = -90;
            goto LABEL_57;
          }
          if ( v5 <= v8 )
            break;
          v18 = *v14;
          *(_QWORD *)(v6 + v8) = v13;
          if ( (v18 & 0x80000000) != 0 )
          {
            __break(0x800u);
            goto LABEL_56;
          }
          v3 = (__int64 *)(v6 + v8);
          v56 = v7;
          v55 = v12;
          v19 = v11;
          v20 = v9;
          v57 = *((_QWORD *)v14 - 2);
          a2 = v13;
          _check_object_size(v13, v18, 0);
          if ( inline_copy_from_user((__int64)a2, v57, v18) )
          {
            v6 = v52;
LABEL_56:
            v29 = -14;
            goto LABEL_57;
          }
          v5 = v51;
          if ( v51 <= v8 + 16 )
            break;
          v21 = *((unsigned int *)v3 + 4);
          v9 = v20;
          v11 = v19;
          v12 = v55;
          v7 = v56;
          v3 = &v58;
          v13 = &a2[v21];
          v6 = v52;
          a2 = (char *)&unk_0;
        }
        if ( v5 <= v8 + 72 )
          break;
        *(_WORD *)(v6 + v8 + 72) = *(_WORD *)(v6 + v8 + 72) & 0xF803
                                 | (4 * (*((_BYTE *)v14 + 11) != 0))
                                 | (8 * (v14[3] & 0xF))
                                 | ((*((_BYTE *)v14 + 13) & 0xF) << 7);
        if ( v5 < v8 + 74 )
          break;
        *(_BYTE *)(v6 + v8 + 74) = *((_BYTE *)v14 + 10);
        if ( v5 < v8 + 76 )
          break;
        v22 = v6 + v8;
        *(_WORD *)(v6 + v8 + 76) = *((_WORD *)v14 + 4);
        if ( v5 < v8 + 78 )
          break;
        *(_BYTE *)(v22 + 78) = 0;
        if ( v5 <= v8 + 88 )
          break;
        v23 = v14[1];
        *(_DWORD *)(v22 + 88) = v23;
        if ( !v23 )
        {
          if ( v5 <= v8 + 88 )
            break;
          *(_DWORD *)(v22 + 88) = *(_DWORD *)(a1 + 120);
        }
        v24 = v59;
        v25 = (__int64 *)(v6 + v8 + 112);
        if ( v25 == v59 || (__int64 *)*v59 != &v58 )
        {
          _list_add_valid_or_report();
        }
        else
        {
          v59 = (__int64 *)(v6 + v8 + 112);
          if ( v5 <= v8 + 112 )
            break;
          *v25 = (__int64)&v58;
          if ( v5 <= v8 + 120 )
            break;
          *(_QWORD *)(v6 + v8 + 120) = v24;
          *v24 = (__int64)v25;
        }
        --v7;
        v8 += 136LL;
        v14 += 8;
        if ( !v7 )
          goto LABEL_38;
      }
      __break(1u);
      v46 = _ReadStatusReg(SP_EL0);
      v47 = *(_QWORD *)(v46 + 80);
      v5 = 136LL * (unsigned int)v3;
      *(_QWORD *)(v46 + 80) = &st54spi_message__alloc_tag;
      v6 = _kmalloc_noprof(v5, 3520);
      *(_QWORD *)(v46 + 80) = v47;
      if ( !v6 )
        goto LABEL_60;
    }
    v11 = 0;
LABEL_38:
    v69[3] = 0;
    v69[4] = 0;
    v70[0] = v70;
    v70[1] = v70;
    raw_spin_lock_irq(a1 + 4);
    v26 = *(_QWORD *)(a1 + 8);
    raw_spin_unlock_irq(a1 + 4);
    if ( v26 )
    {
      v27 = spi_sync(v26, &v58);
      v28 = HIDWORD(v64);
      if ( v27 )
        v28 = v27;
      if ( v28 >= 0 )
        v29 = v11;
      else
        v29 = v28;
      if ( (v28 & 0x80000000) == 0 )
      {
        v30 = v50;
        if ( v50 )
        {
          v31 = _ReadStatusReg(SP_EL0);
          v32 = *(_QWORD *)(a1 + 104);
          v33 = (unsigned int *)(v49 + 16);
          do
          {
            v34 = *((_QWORD *)v33 - 1);
            if ( v34 )
            {
              _check_object_size(v32, *v33, 1);
              v35 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v41 = *(_QWORD *)(v31 + 8);
              _WriteStatusReg(TTBR1_EL1, v41 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v41);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v35);
              v42 = _arch_copy_to_user(v34 & 0xFF7FFFFFFFFFFFFFLL);
              v43 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v45 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v45 - 4096);
              _WriteStatusReg(TTBR1_EL1, v45);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v43);
              if ( v42 )
                goto LABEL_56;
              v32 += *v33;
            }
            --v30;
            v33 += 8;
          }
          while ( v30 );
          v29 = v11;
        }
      }
    }
    else
    {
      v29 = -108;
    }
LABEL_57:
    kfree(v6);
  }
  else
  {
LABEL_60:
    v29 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v29;
}
