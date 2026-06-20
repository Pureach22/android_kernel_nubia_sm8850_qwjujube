__int64 __fastcall mlme_update_tgt_eht_caps_in_cfg(__int64 a1, __int64 a2)
{
  __int64 psoc_ext_obj_fl; // x19
  __int64 context; // x22
  __int64 result; // x0
  __int64 *v7; // x24
  unsigned __int64 *v8; // x23
  __int64 v9; // x22
  __int64 v10; // x10
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x9
  __int64 v17; // x12
  __int64 v18; // x14
  __int64 v19; // x8
  unsigned __int64 v20; // x8
  __int64 v21; // x9
  unsigned __int64 v22; // x10
  unsigned __int64 v23; // x9
  __int64 v24; // x12
  __int64 v25; // x14
  __int64 v26; // x9
  __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 v30; // x9
  __int64 v31; // x9
  __int64 v32; // x9
  bool v33; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  v33 = 0;
  context = _cds_get_context(53, "mlme_update_tgt_eht_caps_in_cfg");
  result = 16;
  if ( psoc_ext_obj_fl && context )
  {
    wlan_psoc_mlme_get_11be_capab(a1, &v33);
    if ( v33 )
    {
      v7 = (__int64 *)(a2 + 465);
      v8 = (unsigned __int64 *)(psoc_ext_obj_fl + 1501);
      v9 = context + 20480;
      *(_BYTE *)(psoc_ext_obj_fl + 1500) = v33;
      qdf_mem_copy((void *)(psoc_ext_obj_fl + 1500), (const void *)(a2 + 464), 0x5Cu);
      if ( *(_BYTE *)(psoc_ext_obj_fl + 2826) == 1 )
      {
        v10 = *(_QWORD *)(psoc_ext_obj_fl + 1509);
        v11 = *v8 & 0xFFFFFFFFFFDFFFFFLL | ((((unsigned __int64)*v7 >> 21) & 1) << 21);
        *v8 = v11;
        v12 = v11 & 0xFFFFFFF1FFFFFFFFLL | ((((unsigned __int64)*v7 >> 33) & 7) << 33);
        *v8 = v12;
        v13 = v12 & 0xFFFFFF8FFFFFFFFFLL | ((((unsigned __int64)*v7 >> 36) & 7) << 36);
        *v8 = v13;
        *v8 = v13 & 0xFFFFFC7FFFFFFFFFLL | ((((unsigned __int64)*v7 >> 39) & 7) << 39);
        v14 = v10 & 0xFFFFFFFFFFFEFFFFLL | (((*(_QWORD *)(a2 + 473) >> 16) & 1LL) << 16);
        *(_QWORD *)(psoc_ext_obj_fl + 1509) = v14;
        v15 = v14 & 0xFFFFFFFFFFFDFFFFLL | (((*(_QWORD *)(a2 + 473) >> 17) & 1LL) << 17);
        *(_QWORD *)(psoc_ext_obj_fl + 1509) = v15;
        *(_QWORD *)(psoc_ext_obj_fl + 1509) = v15 & 0xFFFFFFFFFFFBFFFFLL | (((*(_QWORD *)(a2 + 473) >> 18) & 1LL) << 18);
      }
      else
      {
        v16 = *(_QWORD *)(psoc_ext_obj_fl + 1509) & 0xFFFFFFFFFFF8FFFFLL;
        *v8 &= 0xFFFFFC01FFDFFFFFLL;
        *(_QWORD *)(psoc_ext_obj_fl + 1509) = v16;
        v17 = *(_QWORD *)(v9 + 1677);
        v18 = *(_QWORD *)(v9 + 1769);
        *(_QWORD *)(v9 + 1585) &= ~0x200000uLL;
        v19 = *(_QWORD *)(v9 + 1861);
        *(_QWORD *)(v9 + 1677) = v17 & 0xFFFFFFFFFFDFFFFFLL;
        *(_QWORD *)(v9 + 1769) = v18 & 0xFFFFFFFFFFDFFFFFLL;
        *(_QWORD *)(v9 + 1861) = v19 & 0xFFFFFFFFFFDFFFFFLL;
      }
      if ( *(_BYTE *)(psoc_ext_obj_fl + 2827) == 1 )
      {
        v20 = *v8 & 0xFFFFFFFFFFBFFFFFLL | ((((unsigned __int64)*v7 >> 22) & 1) << 22);
        *v8 = v20;
        v21 = *v7;
        v22 = *v7 & 0x7000000;
        if ( v22 >= 0x2000001 )
        {
          v20 = v20 & 0xFFFFFFFFF8FFFFFFLL | v22;
          *v8 = v20;
          v21 = *v7;
        }
        if ( ((unsigned int)v21 & 0x38000000) >= 0x10000001uLL )
        {
          v20 = v20 & 0xFFFFFFFFC7FFFFFFLL | v21 & 0x38000000;
          *v8 = v20;
          v21 = *v7;
        }
        v23 = v21 & 0x1C0000000LL;
        if ( v23 >= 0x80000001 )
        {
          v20 = v20 & 0xFFFFFFFE3FFFFFFFLL | v23;
          *v8 = v20;
        }
        if ( (v20 & 0x4000000) != 0 && (*(_BYTE *)(a2 + 413) & 1) == 0 )
        {
          v20 = v20 & 0xFFFFFFFFF8FFFFFFLL | 0x3000000;
          *v8 = v20;
        }
        if ( (v20 & 0x20000000) != 0 && (*(_BYTE *)(a2 + 413) & 1) == 0 )
        {
          v20 = v20 & 0xFFFFFFFFC7FFFFFFLL | 0x18000000;
          *v8 = v20;
        }
        if ( (v20 & 0x100000000LL) != 0 && (*(_BYTE *)(a2 + 413) & 1) == 0 )
          *v8 = v20 & 0xFFFFFFFE3FFFFFFFLL | 0xC0000000;
      }
      else
      {
        *v8 &= 0xFFFFFFFE00BFFFFFLL;
        v24 = *(_QWORD *)(v9 + 1677);
        v25 = *(_QWORD *)(v9 + 1769);
        *(_QWORD *)(v9 + 1585) &= ~0x400000uLL;
        v26 = *(_QWORD *)(v9 + 1861);
        *(_QWORD *)(v9 + 1677) = v24 & 0xFFFFFFFFFFBFFFFFLL;
        *(_QWORD *)(v9 + 1769) = v25 & 0xFFFFFFFFFFBFFFFFLL;
        *(_QWORD *)(v9 + 1861) = v26 & 0xFFFFFFFFFFBFFFFFLL;
      }
      v27 = *(_QWORD *)(psoc_ext_obj_fl + 1572);
      result = 0;
      *(_QWORD *)(psoc_ext_obj_fl + 1656) = *(_QWORD *)(psoc_ext_obj_fl + 1564);
      v28 = *(_QWORD *)(psoc_ext_obj_fl + 1580);
      *(_QWORD *)(psoc_ext_obj_fl + 1664) = v27;
      LODWORD(v27) = *(_DWORD *)(psoc_ext_obj_fl + 1588);
      *(_QWORD *)(psoc_ext_obj_fl + 1672) = v28;
      *(_DWORD *)(psoc_ext_obj_fl + 1680) = v27;
      v29 = *(_QWORD *)(psoc_ext_obj_fl + 1540);
      *(_QWORD *)(psoc_ext_obj_fl + 1624) = *(_QWORD *)(psoc_ext_obj_fl + 1532);
      *(_QWORD *)(psoc_ext_obj_fl + 1632) = v29;
      v30 = *(_QWORD *)(psoc_ext_obj_fl + 1556);
      *(_QWORD *)(psoc_ext_obj_fl + 1640) = *(_QWORD *)(psoc_ext_obj_fl + 1548);
      *(_QWORD *)(psoc_ext_obj_fl + 1648) = v30;
      v31 = *(_QWORD *)(psoc_ext_obj_fl + 1508);
      *(_QWORD *)(psoc_ext_obj_fl + 1592) = *(_QWORD *)(psoc_ext_obj_fl + 1500);
      *(_QWORD *)(psoc_ext_obj_fl + 1600) = v31;
      v32 = *(_QWORD *)(psoc_ext_obj_fl + 1524);
      *(_QWORD *)(psoc_ext_obj_fl + 1608) = *(_QWORD *)(psoc_ext_obj_fl + 1516);
      *(_QWORD *)(psoc_ext_obj_fl + 1616) = v32;
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
