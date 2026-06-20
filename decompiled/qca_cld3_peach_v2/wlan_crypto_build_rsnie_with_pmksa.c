char *__fastcall wlan_crypto_build_rsnie_with_pmksa(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x20
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int random_pmkid; // w23
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char *v34; // x22
  unsigned __int8 v35; // w24
  char *v36; // x21
  char *v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _WORD *v46; // x23
  int v47; // w8
  int v48; // w8
  char *v49; // x22
  int v50; // w8
  char v51; // w8
  char *v52; // x23
  int v53; // w8
  char v54; // w8
  char v55; // w8
  char v56; // w8
  int v57; // w8
  int v59; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v60; // [xsp+8h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
    if ( comp_private_obj )
    {
      v15 = comp_private_obj;
      v16 = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
      if ( v16 )
      {
        random_pmkid = wlan_crypto_get_random_pmkid(v16);
        if ( random_pmkid < 0xD )
        {
          if ( a3 )
            goto LABEL_13;
LABEL_11:
          if ( !random_pmkid )
          {
            v35 = 0;
            v36 = nullptr;
            goto LABEL_24;
          }
LABEL_13:
          if ( a3 )
            v35 = random_pmkid + 1;
          else
            v35 = random_pmkid;
          if ( v35 >= 2u )
            qdf_trace_msg(
              0x1Cu,
              8u,
              "%s: Appending %d PMKIDs to the RSN IE",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "generate_pmkid");
          v37 = (char *)_qdf_mem_malloc(16LL * v35, "generate_pmkid", 3174);
          v36 = v37;
          if ( v37 )
          {
            if ( a3 )
            {
              qdf_mem_copy(v37, (const void *)(a3 + 6), 0x10u);
              v37 = v36 + 16;
            }
            if ( random_pmkid )
              get_random_bytes(v37, 16 * random_pmkid);
          }
          else
          {
            qdf_trace_msg(
              0x1Cu,
              2u,
              "%s: PMKID memory allocation failed",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "generate_pmkid");
          }
LABEL_24:
          *(_DWORD *)a2 = 65584;
          v46 = (_WORD *)(a2 + 4);
          v47 = *(_DWORD *)(v15 + 8);
          if ( (v47 & 2) != 0 )
          {
            v59 = 44830464;
          }
          else if ( (v47 & 8) != 0 )
          {
            v59 = 78384896;
          }
          else
          {
            if ( (v47 & 0x80) != 0 )
            {
              v48 = 179048192;
            }
            else if ( (v47 & 0x200) != 0 )
            {
              v48 = 145493760;
            }
            else
            {
              if ( (v47 & 0x400) == 0 )
                goto LABEL_36;
              v48 = 162270976;
            }
            v59 = v48;
          }
          qdf_mem_copy((void *)(a2 + 4), &v59, 4u);
          v46 = (_WORD *)(a2 + 8);
LABEL_36:
          *v46 = 0;
          v49 = (char *)(v46 + 1);
          v50 = *(_DWORD *)(v15 + 4);
          if ( (v50 & 0x80) != 0 )
          {
            *(_BYTE *)v46 = 1;
            v59 = 179048192;
            qdf_mem_copy(v46 + 1, &v59, 4u);
            v50 = *(_DWORD *)(v15 + 4);
            v49 = (char *)(v46 + 3);
            if ( (v50 & 0x400) == 0 )
            {
LABEL_38:
              if ( (v50 & 8) == 0 )
                goto LABEL_39;
              goto LABEL_66;
            }
          }
          else if ( (v50 & 0x400) == 0 )
          {
            goto LABEL_38;
          }
          v54 = *(_BYTE *)v46 + 1;
          v59 = 162270976;
          *(_BYTE *)v46 = v54;
          qdf_mem_copy(v49, &v59, 4u);
          v50 = *(_DWORD *)(v15 + 4);
          v49 += 4;
          if ( (v50 & 8) == 0 )
          {
LABEL_39:
            if ( (v50 & 0x200) == 0 )
              goto LABEL_40;
            goto LABEL_67;
          }
LABEL_66:
          v55 = *(_BYTE *)v46;
          v59 = 78384896;
          *(_BYTE *)v46 = v55 + 1;
          qdf_mem_copy(v49, &v59, 4u);
          v50 = *(_DWORD *)(v15 + 4);
          v49 += 4;
          if ( (v50 & 0x200) == 0 )
          {
LABEL_40:
            if ( (v50 & 2) == 0 )
              goto LABEL_42;
            goto LABEL_41;
          }
LABEL_67:
          v56 = *(_BYTE *)v46 + 1;
          v59 = 145493760;
          *(_BYTE *)v46 = v56;
          qdf_mem_copy(v49, &v59, 4u);
          v49 += 4;
          if ( (*(_DWORD *)(v15 + 4) & 2) == 0 )
          {
LABEL_42:
            *(_WORD *)v49 = 0;
            v52 = v49 + 2;
            v53 = *(_DWORD *)(v15 + 20);
            if ( (v53 & 0x4000) != 0 )
            {
              *v49 = 1;
              v59 = 9846784;
              qdf_mem_copy(v49 + 2, &v59, 4u);
              v52 = v49 + 6;
              goto LABEL_90;
            }
            if ( (v53 & 1) != 0 )
            {
              *v49 = 1;
              v59 = 28053248;
              qdf_mem_copy(v49 + 2, &v59, 4u);
              v53 = *(_DWORD *)(v15 + 20);
              v52 = v49 + 6;
              if ( (v53 & 2) == 0 )
              {
LABEL_45:
                if ( (v53 & 0x20) == 0 )
                  goto LABEL_46;
                goto LABEL_72;
              }
            }
            else if ( (v53 & 2) == 0 )
            {
              goto LABEL_45;
            }
            ++*v49;
            v59 = 44830464;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x20) == 0 )
            {
LABEL_46:
              if ( (v53 & 0x40) == 0 )
                goto LABEL_47;
              goto LABEL_73;
            }
LABEL_72:
            ++*v49;
            v59 = 61607680;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x40) == 0 )
            {
LABEL_47:
              if ( (v53 & 0x80) == 0 )
                goto LABEL_48;
              goto LABEL_74;
            }
LABEL_73:
            ++*v49;
            v59 = 78384896;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x80) == 0 )
            {
LABEL_48:
              if ( (v53 & 0x100) == 0 )
                goto LABEL_49;
              goto LABEL_75;
            }
LABEL_74:
            ++*v49;
            v59 = 95162112;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x100) == 0 )
            {
LABEL_49:
              if ( (v53 & 0x400) == 0 )
                goto LABEL_50;
              goto LABEL_76;
            }
LABEL_75:
            ++*v49;
            v59 = 111939328;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x400) == 0 )
            {
LABEL_50:
              if ( (v53 & 0x800) == 0 )
                goto LABEL_51;
              goto LABEL_77;
            }
LABEL_76:
            ++*v49;
            v59 = 145493760;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x800) == 0 )
            {
LABEL_51:
              if ( (v53 & 0x10000) == 0 )
                goto LABEL_52;
              goto LABEL_78;
            }
LABEL_77:
            ++*v49;
            v59 = 162270976;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x10000) == 0 )
            {
LABEL_52:
              if ( (v53 & 0x20000) == 0 )
                goto LABEL_53;
              goto LABEL_79;
            }
LABEL_78:
            ++*v49;
            v59 = 195825408;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x20000) == 0 )
            {
LABEL_53:
              if ( (v53 & 0x40000) == 0 )
                goto LABEL_54;
              goto LABEL_80;
            }
LABEL_79:
            ++*v49;
            v59 = 212602624;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x40000) == 0 )
            {
LABEL_54:
              if ( (v53 & 0x80000) == 0 )
                goto LABEL_55;
              goto LABEL_81;
            }
LABEL_80:
            ++*v49;
            v59 = 246157056;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x80000) == 0 )
            {
LABEL_55:
              if ( (v53 & 0x100000) == 0 )
                goto LABEL_56;
              goto LABEL_82;
            }
LABEL_81:
            ++*v49;
            v59 = 262934272;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x100000) == 0 )
            {
LABEL_56:
              if ( (v53 & 0x200000) == 0 )
                goto LABEL_57;
              goto LABEL_83;
            }
LABEL_82:
            ++*v49;
            v59 = 279711488;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x200000) == 0 )
            {
LABEL_57:
              if ( (v53 & 0x400000) == 0 )
                goto LABEL_58;
              goto LABEL_84;
            }
LABEL_83:
            ++*v49;
            v59 = 296488704;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x400000) == 0 )
            {
LABEL_58:
              if ( (v53 & 0x800000) == 0 )
                goto LABEL_59;
              goto LABEL_85;
            }
LABEL_84:
            ++*v49;
            v59 = 313265920;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x800000) == 0 )
            {
LABEL_59:
              if ( (v53 & 0x8000) == 0 )
                goto LABEL_60;
              goto LABEL_86;
            }
LABEL_85:
            ++*v49;
            v59 = 43675472;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x8000) == 0 )
            {
LABEL_60:
              if ( (v53 & 0x8000000) == 0 )
                goto LABEL_61;
              goto LABEL_87;
            }
LABEL_86:
            ++*v49;
            v59 = 26898256;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x8000000) == 0 )
            {
LABEL_61:
              if ( (v53 & 0x1000000) == 0 )
                goto LABEL_62;
              goto LABEL_88;
            }
LABEL_87:
            ++*v49;
            v59 = 413929216;
            qdf_mem_copy(v52, &v59, 4u);
            v53 = *(_DWORD *)(v15 + 20);
            v52 += 4;
            if ( (v53 & 0x1000000) == 0 )
            {
LABEL_62:
              if ( (v53 & 0x10000000) == 0 )
              {
LABEL_90:
                *v52 = *(_BYTE *)(v15 + 152);
                v52[1] = *(_BYTE *)(v15 + 153);
                if ( (*(_WORD *)(v15 + 152) & 0x80) == 0 )
                {
                  if ( v36 )
                  {
                    v52[2] = v35;
                    v52[3] = 0;
                    qdf_mem_copy(v52 + 4, v36, 16 * (unsigned int)v35);
                    v34 = &v52[16 * v35 + 4];
                  }
                  else
                  {
                    v34 = v52 + 2;
                  }
                  goto LABEL_104;
                }
                v34 = v52 + 4;
                if ( v36 )
                {
                  v52[2] = v35;
                  v52[3] = 0;
                  qdf_mem_copy(v52 + 4, v36, 16 * (unsigned int)v35);
                  v34 += 16 * v35;
                  v57 = *(_DWORD *)(v15 + 12);
                  if ( (v57 & 0x40) == 0 )
                    goto LABEL_96;
                }
                else
                {
                  *((_WORD *)v52 + 1) = 0;
                  v57 = *(_DWORD *)(v15 + 12);
                  if ( (v57 & 0x40) == 0 )
                  {
LABEL_96:
                    if ( (v57 & 0x800) != 0 )
                    {
                      v59 = 195825408;
                      qdf_mem_copy(v34, &v59, 4u);
                      v57 = *(_DWORD *)(v15 + 12);
                      v34 += 4;
                      if ( (v57 & 0x100) == 0 )
                      {
LABEL_98:
                        if ( (v57 & 0x1000) == 0 )
                          goto LABEL_104;
                        goto LABEL_102;
                      }
                    }
                    else if ( (v57 & 0x100) == 0 )
                    {
                      goto LABEL_98;
                    }
                    v59 = 229379840;
                    qdf_mem_copy(v34, &v59, 4u);
                    v34 += 4;
                    if ( (*(_DWORD *)(v15 + 12) & 0x1000) == 0 )
                    {
LABEL_104:
                      *(_BYTE *)(a2 + 1) = (_BYTE)v34 - a2 - 2;
                      _qdf_mem_free((__int64)v36);
                      goto LABEL_105;
                    }
LABEL_102:
                    v59 = 212602624;
                    qdf_mem_copy(v34, &v59, 4u);
                    v34 += 4;
                    goto LABEL_104;
                  }
                }
                v59 = 111939328;
                qdf_mem_copy(v34, &v59, 4u);
                v57 = *(_DWORD *)(v15 + 12);
                v34 += 4;
                goto LABEL_96;
              }
LABEL_89:
              ++*v49;
              v59 = 430706432;
              qdf_mem_copy(v52, &v59, 4u);
              v52 += 4;
              goto LABEL_90;
            }
LABEL_88:
            ++*v49;
            v59 = 229379840;
            qdf_mem_copy(v52, &v59, 4u);
            v52 += 4;
            if ( (*(_DWORD *)(v15 + 20) & 0x10000000) == 0 )
              goto LABEL_90;
            goto LABEL_89;
          }
LABEL_41:
          v51 = *(_BYTE *)v46;
          v59 = 44830464;
          *(_BYTE *)v46 = v51 + 1;
          qdf_mem_copy(v49, &v59, 4u);
          v49 += 4;
          goto LABEL_42;
        }
      }
      else
      {
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: crypto_priv NULL",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "wlan_crypto_get_param");
      }
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: Invalid random PMKID count, therefore not appending random PMKID",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "generate_pmkid");
      random_pmkid = 0;
      if ( a3 )
        goto LABEL_13;
      goto LABEL_11;
    }
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_crypto_vdev_get_comp_params");
    v34 = nullptr;
  }
  else
  {
    v34 = nullptr;
  }
LABEL_105:
  _ReadStatusReg(SP_EL0);
  return v34;
}
