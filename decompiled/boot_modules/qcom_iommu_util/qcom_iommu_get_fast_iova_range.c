__int64 __fastcall qcom_iommu_get_fast_iova_range(__int64 a1, unsigned __int64 *a2, unsigned __int64 *a3)
{
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v8; // x0
  __int64 v9; // x1
  unsigned __int64 v10; // x25
  unsigned __int64 v11; // x26
  __int64 v12; // x0
  __int64 v13; // x22
  __int64 property; // x0
  unsigned __int64 v15; // x20
  int v16; // w21
  int v17; // w0
  int v18; // w5
  unsigned __int64 v19; // x10
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x9
  __int64 v22; // x15
  unsigned __int64 v23; // x14
  unsigned int v24; // w16
  unsigned __int64 v25; // x15
  __int64 v26; // x16
  int v27; // w17
  unsigned int v28; // w0
  unsigned __int64 v29; // x15
  unsigned __int64 v30; // x16
  __int64 v31; // x8
  _DWORD *v32; // x8
  _QWORD *v33; // x20
  _QWORD *v34; // x0
  _QWORD *v35; // x21
  _QWORD **v36; // x2
  _QWORD *v37; // x1
  _QWORD *v38; // x0
  unsigned __int64 v39; // x28
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x10
  _QWORD *v42; // x27
  unsigned __int64 v43; // x9
  unsigned __int64 v44; // x10
  __int64 v45; // x25
  __int64 v46; // x8
  _QWORD *v47; // x9
  _QWORD *v48; // x0
  __int64 v49; // x8
  unsigned __int64 v50; // x28
  unsigned __int64 v51; // x9
  _QWORD *v52; // x27
  unsigned __int64 v53; // x8
  unsigned __int64 v54; // x11
  _QWORD *v55; // x10
  unsigned __int64 v56; // x11
  unsigned __int64 v57; // x25
  _QWORD *v58; // x9
  char v59; // w20
  unsigned int v60; // w21
  unsigned __int64 v61; // x8
  unsigned __int64 v62; // x8
  char *v63; // x9
  unsigned __int64 v64; // x8
  _QWORD *v65; // x0
  _QWORD *v66; // x8
  _QWORD *v67; // x28
  _QWORD *v68; // x9
  _QWORD *v69; // [xsp+8h] [xbp-78h] BYREF
  _QWORD **v70; // [xsp+10h] [xbp-70h]
  _QWORD v71[2]; // [xsp+18h] [xbp-68h] BYREF
  __int64 v72; // [xsp+28h] [xbp-58h] BYREF
  __int64 v73; // [xsp+30h] [xbp-50h]
  __int64 v74; // [xsp+38h] [xbp-48h]
  __int64 v75; // [xsp+40h] [xbp-40h]
  __int64 v76; // [xsp+48h] [xbp-38h]
  __int64 v77; // [xsp+50h] [xbp-30h]
  __int64 v78; // [xsp+58h] [xbp-28h]
  __int64 v79; // [xsp+60h] [xbp-20h]
  __int64 v80; // [xsp+68h] [xbp-18h]
  __int64 v81; // [xsp+70h] [xbp-10h]
  __int64 v82; // [xsp+78h] [xbp-8h]

  result = 4294967274LL;
  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 && a3 )
  {
    v5 = *(_QWORD *)(a1 + 744);
    if ( !v5 )
      goto LABEL_10;
    v80 = 0;
    v81 = 0;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    if ( (unsigned int)_of_parse_phandle_with_args(v5, "qcom,iommu-group", 0, 0, 0, &v72) || (v8 = v72) == 0 )
    {
      v8 = *(_QWORD *)(a1 + 744);
      if ( !v8 )
        goto LABEL_10;
    }
    if ( of_find_property(v8, "qcom,iommu-dma-addr-pool", 0) )
    {
      _warn_printk("qcom,iommu-dma-addr-pool is deprecated. Switch to using iommu-addresses.");
      __break(0x800u);
LABEL_10:
      result = 4294967274LL;
      goto LABEL_11;
    }
    v9 = *(_QWORD *)(a1 + 744);
    v71[0] = v71;
    v71[1] = v71;
    v69 = &v69;
    v70 = &v69;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    of_phandle_iterator_init(&v72, v9, "memory-region", 0, 0);
    if ( (unsigned int)of_phandle_iterator_next(&v72) )
    {
LABEL_15:
      v10 = 0;
      v11 = 0xFFFFFFFFLL;
    }
    else
    {
      while ( !of_find_property(v79, "iommu-addresses", 0) )
      {
        if ( (unsigned int)of_phandle_iterator_next(&v72) )
          goto LABEL_15;
      }
      v31 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 824) + 64LL) + 16LL);
      if ( v31 )
      {
        v32 = *(_DWORD **)(v31 + 80);
        if ( v32 )
        {
          if ( *(v32 - 1) != -2072681516 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD *))v32)(a1, v71);
        }
      }
      v33 = (_QWORD *)v71[0];
      if ( (_QWORD *)v71[0] == v71 )
      {
        v10 = 0;
        v11 = 0;
        v59 = 0;
        v60 = -22;
      }
      else
      {
        _ReadStatusReg(SP_EL0);
        do
        {
          v34 = (_QWORD *)kmemdup_noprof(v33, 48, 3264);
          v35 = v34;
          if ( !v34 )
          {
            v10 = 0;
            v11 = 0;
            v59 = 0;
            v60 = -12;
            goto LABEL_110;
          }
          v36 = &v69;
          do
            v36 = (_QWORD **)*v36;
          while ( v36 != &v69 && (unsigned __int64)v36[2] <= v34[2] );
          v37 = v36[1];
          if ( v34 == v36 || v37 == v34 || (_QWORD **)*v37 != v36 )
          {
            _list_add_valid_or_report(v34, v37);
          }
          else
          {
            v36[1] = v34;
            *v34 = v36;
            v34[1] = v37;
            *v37 = v34;
          }
          v38 = (_QWORD *)v35[1];
          if ( v38 != &v69 )
          {
            v39 = v35[2];
            do
            {
              v40 = v38[2];
              v41 = v39 - 1;
              v42 = (_QWORD *)v38[1];
              v43 = v40 + v38[3] - 1;
              if ( v39 && v41 > v43 )
                break;
              if ( v39 >= v40 )
                v39 = v38[2];
              v44 = v35[3] + v41;
              v45 = v44 <= v43 ? v40 + v38[3] - 1 : v44;
              if ( (_QWORD *)*v42 == v38 && (v46 = *v38, *(_QWORD **)(*v38 + 8LL) == v38) )
              {
                *(_QWORD *)(v46 + 8) = v42;
                *v42 = v46;
              }
              else
              {
                _list_del_entry_valid_or_report(v38);
                v38 = v47;
              }
              *v38 = 0xDEAD000000000100LL;
              v38[1] = 0xDEAD000000000122LL;
              kfree(v38);
              v38 = v42;
              v35[2] = v39;
              v35[3] = v45 - v39 + 1;
            }
            while ( v42 != &v69 );
          }
          v48 = (_QWORD *)*v35;
          if ( (_QWORD **)*v35 != &v69 )
          {
            v50 = v35[2];
            v49 = v35[3];
            do
            {
              v51 = v48[2];
              v52 = (_QWORD *)*v48;
              v53 = v49 + v50 - 1;
              v54 = v51 - 1;
              if ( v51 && v53 < v54 )
                break;
              v55 = (_QWORD *)v48[1];
              if ( v50 >= v51 )
                v50 = v48[2];
              v56 = v48[3] + v54;
              v57 = v53 <= v56 ? v56 : v53;
              if ( (_QWORD *)*v55 == v48 && (_QWORD *)v52[1] == v48 )
              {
                v52[1] = v55;
                *v55 = v52;
              }
              else
              {
                _list_del_entry_valid_or_report(v48);
                v48 = v58;
              }
              *v48 = 0xDEAD000000000100LL;
              v48[1] = 0xDEAD000000000122LL;
              kfree(v48);
              v48 = v52;
              v49 = v57 - v50 + 1;
              v35[2] = v50;
              v35[3] = v49;
            }
            while ( v52 != &v69 );
          }
          v33 = (_QWORD *)*v33;
        }
        while ( v33 != v71 );
        if ( v69[2] )
          v10 = 0;
        else
          v10 = v69[3];
        v60 = 0;
        v62 = (unsigned __int64)v70[2];
        if ( HIDWORD(v62) )
        {
          v59 = 1;
          v11 = 0xFFFFFFFFLL;
        }
        else
        {
          v59 = 1;
          v63 = (char *)v70[3] + v62;
          v64 = v62 - 1;
          if ( (unsigned __int64)(v63 - 0x100000000LL) >= 0xFFFFFFFF00000001LL )
            v11 = 0xFFFFFFFFLL;
          else
            v11 = v64;
        }
      }
LABEL_110:
      v65 = v69;
      if ( v69 != &v69 )
      {
        do
        {
          v67 = (_QWORD *)*v65;
          v66 = (_QWORD *)v65[1];
          if ( (_QWORD *)*v66 == v65 && (_QWORD *)v67[1] == v65 )
          {
            v67[1] = v66;
            *v66 = v67;
          }
          else
          {
            _list_del_entry_valid_or_report(v65);
            v65 = v68;
          }
          *v65 = 0xDEAD000000000100LL;
          v65[1] = 0xDEAD000000000122LL;
          kfree(v65);
          v65 = v67;
        }
        while ( v67 != &v69 );
      }
      iommu_put_resv_regions(a1, v71);
      if ( (v59 & 1) == 0 )
      {
        dev_err(a1, "Parsing iommu-addresses into set failed with %d\n", v60);
        result = v60;
        goto LABEL_11;
      }
    }
    v12 = *(_QWORD *)(a1 + 744);
    if ( !v12 )
      goto LABEL_10;
    LODWORD(v71[0]) = 0;
    v80 = 0;
    v81 = 0;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    if ( (unsigned int)_of_parse_phandle_with_args(v12, "qcom,iommu-group", 0, 0, 0, &v72) || (v13 = v72) == 0 )
    {
      v13 = *(_QWORD *)(a1 + 744);
      if ( !v13 )
        goto LABEL_10;
    }
    property = of_get_property(v13, "qcom,iommu-geometry", v71);
    if ( property )
    {
      v15 = property;
      SLODWORD(v71[0]) >>= 2;
      v16 = of_n_addr_cells(v13);
      v17 = of_n_size_cells(v13);
      v18 = v17;
      if ( !v16 || !v17 || SLODWORD(v71[0]) % (v17 + v16) )
      {
        dev_err(
          a1,
          "%s Invalid length %d. Address cells %d. Size cells %d\n",
          "qcom,iommu-geometry",
          LODWORD(v71[0]),
          v16,
          v17);
        goto LABEL_10;
      }
      v19 = v15 + 4LL * SLODWORD(v71[0]);
      if ( v15 < v19 )
      {
        v20 = 0;
        v21 = 0;
        while ( 1 )
        {
          v22 = 0;
          v23 = 0;
          do
          {
            v24 = *(_DWORD *)(v15 + 4 * v22++);
            v23 = bswap32(v24) | (v23 << 32);
          }
          while ( v16 != (_DWORD)v22 );
          v25 = 0;
          v26 = 4LL * v16;
          v27 = v18;
          do
          {
            v28 = *(_DWORD *)(v15 + v26);
            --v27;
            v26 += 4;
            v25 = bswap32(v28) | (v25 << 32);
          }
          while ( v27 );
          if ( HIDWORD(v23) )
            break;
          v29 = v23 + v25 - 1;
          if ( HIDWORD(v29) )
            break;
          v15 += 4LL * (v18 + v16);
          if ( v20 >= v23 )
            v30 = v23;
          else
            v30 = v20;
          if ( !v23 )
            v30 = v20;
          if ( v20 )
            v20 = v30;
          else
            v20 = v23;
          if ( v21 <= v29 )
            v21 = v29;
          if ( v15 >= v19 )
            goto LABEL_94;
        }
        printk(&unk_11BDF);
        goto LABEL_10;
      }
      v20 = 0;
      v21 = 0;
    }
    else
    {
      v20 = 0;
      v21 = 0xFFFFFFFFLL;
    }
LABEL_94:
    result = 0;
    if ( v20 >= v10 )
      v20 = v10;
    *a2 = v20;
    if ( v21 <= v11 )
      v61 = v11;
    else
      v61 = v21;
    *a3 = v61;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
