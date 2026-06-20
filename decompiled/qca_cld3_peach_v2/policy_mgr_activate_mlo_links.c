__int64 __fastcall policy_mgr_activate_mlo_links(__int64 a1, __int64 a2, unsigned __int8 a3, unsigned __int8 *a4)
{
  unsigned __int8 v5; // w20
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x25
  int v42; // w23
  unsigned __int8 *v43; // x8
  const void *v44; // x20
  __int64 v45; // x4
  __int64 v46; // x5
  __int64 v47; // x6
  __int64 v48; // x7
  unsigned __int8 *v49; // x21
  __int64 v50; // x24
  char v51; // w22
  __int64 v52; // x4
  __int64 v53; // x5
  __int64 v54; // x6
  __int64 v55; // x7
  __int64 v56; // x9
  __int64 result; // x0
  const char *v58; // x2
  unsigned int *v59; // x8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  _WORD *v76; // x6
  __int64 v77; // x0
  unsigned int v78; // w1
  unsigned int v79; // w2
  int v80; // w3
  int v81; // w5
  __int64 v82; // [xsp+8h] [xbp-58h]
  __int64 v83; // [xsp+10h] [xbp-50h]
  __int64 v84; // [xsp+18h] [xbp-48h]
  unsigned __int8 v86; // [xsp+28h] [xbp-38h]
  int v87; // [xsp+30h] [xbp-30h]
  unsigned __int16 v88; // [xsp+3Ch] [xbp-24h] BYREF
  _WORD v89[2]; // [xsp+40h] [xbp-20h] BYREF
  unsigned __int8 v90[4]; // [xsp+44h] [xbp-1Ch] BYREF
  __int64 v91; // [xsp+48h] [xbp-18h] BYREF
  __int64 v92; // [xsp+50h] [xbp-10h]
  __int64 v93; // [xsp+58h] [xbp-8h]

  v5 = a2;
  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v88 = 0;
  v91 = 0;
  v92 = 0;
  *(_WORD *)v90 = 0;
  v89[0] = 0;
  v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v7 )
  {
    v16 = v7;
    v83 = v7;
    if ( wlan_cm_is_vdev_connected(v7, v8, v9, v10, v11, v12, v13, v14, v15) )
    {
      if ( (wlan_vdev_mlme_is_mlo_vdev(v16, v17, v18, v19, v20, v21, v22, v23, v24) & 1) != 0 )
      {
        v82 = a1;
        mlo_get_ml_vdev_list(v16, &v88, &v91);
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: Num active links: %d, ML vdev cnt: %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "policy_mgr_activate_mlo_links",
          a3,
          v88);
        if ( v88 )
        {
          v41 = 0;
          v42 = 0;
          v86 = a3;
          v87 = 0;
          v84 = a3;
          while ( v41 != 2 )
          {
            if ( (v41 & 0x1FFFFFFFFFFFFFFFLL) == 2 )
              goto LABEL_43;
            v43 = (unsigned __int8 *)*(&v91 + v41);
            v44 = v43 + 74;
            if ( v43 == (unsigned __int8 *)-74LL )
            {
              v47 = 0;
              v45 = 0;
              v46 = 0;
              v48 = 0;
            }
            else
            {
              v45 = v43[74];
              v46 = v43[75];
              v47 = v43[76];
              v48 = v43[79];
            }
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: link addr: %02x:%02x:%02x:**:**:%02x",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "policy_mgr_activate_mlo_links",
              v45,
              v46,
              v47,
              v48);
            if ( !v86 )
              goto LABEL_6;
            v50 = v84;
            v49 = a4;
            v51 = 0;
            do
            {
              if ( v49 )
              {
                v52 = *v49;
                v53 = v49[1];
                v54 = v49[2];
                v55 = v49[5];
              }
              else
              {
                v54 = 0;
                v52 = 0;
                v53 = 0;
                v55 = 0;
              }
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: active addr: %02x:%02x:%02x:**:**:%02x",
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                "policy_mgr_activate_mlo_links",
                v52,
                v53,
                v54,
                v55);
              if ( !(unsigned int)qdf_mem_cmp(v44, v49, 6u) )
              {
                if ( (unsigned __int8)v42 > 1u )
                  goto LABEL_42;
                v56 = (unsigned __int8)v42++;
                v90[v56] = *(_BYTE *)(*(&v91 + v41) + 168);
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: Link address match",
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  "policy_mgr_activate_mlo_links");
                v51 = 1;
              }
              --v50;
              v49 += 6;
            }
            while ( v50 );
            if ( (v51 & 1) == 0 )
            {
LABEL_6:
              if ( (unsigned __int8)v87 > 1u )
                goto LABEL_42;
              *((_BYTE *)v89 + (unsigned __int8)v87++) = *(_BYTE *)(*(&v91 + v41) + 168);
              qdf_trace_msg(
                0x4Fu,
                2u,
                "%s: No link address match",
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                "policy_mgr_activate_mlo_links");
            }
            if ( v88 <= (unsigned int)(unsigned __int16)++v41 )
              goto LABEL_32;
          }
          goto LABEL_42;
        }
        v42 = 0;
        v87 = 0;
LABEL_32:
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: active vdev cnt: %d, inactive vdev cnt: %d",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "policy_mgr_activate_mlo_links",
          (unsigned __int8)v42,
          (unsigned __int8)v87);
        if ( (_BYTE)v42 )
        {
          if ( (policy_mgr_is_emlsr_sta_concurrency_present(v82) & 1) != 0 )
          {
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: Concurrency exists, cannot enter EMLSR mode",
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              "policy_mgr_activate_mlo_links");
          }
          else
          {
            if ( (_BYTE)v87 )
            {
              v76 = v89;
              v77 = v82;
              v78 = 1;
              v79 = 6;
              v80 = v42;
              v81 = v87;
            }
            else
            {
              v77 = v82;
              v78 = 2;
              v79 = 1;
              v80 = v42;
              v81 = 0;
              v76 = nullptr;
            }
            policy_mgr_mlo_sta_set_link_ext(
              v77,
              v78,
              v79,
              v80,
              v90,
              v81,
              (__int64)v76,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75);
          }
        }
        v59 = (unsigned int *)v88;
        if ( v88 )
        {
          mlo_release_vdev_ref(v91);
          v59 = (unsigned int *)v88;
          if ( v88 >= 2u )
          {
            mlo_release_vdev_ref(v92);
            v59 = (unsigned int *)v88;
            if ( v88 > 2u )
            {
LABEL_42:
              __break(0x5512u);
LABEL_43:
              __break(1u);
            }
          }
        }
        goto LABEL_29;
      }
      v58 = "%s: vdev is not mlo vdev";
    }
    else
    {
      v58 = "%s: vdev is not in connected state";
    }
    qdf_trace_msg(0x4Fu, 2u, v58, v17, v18, v19, v20, v21, v22, v23, v24, "policy_mgr_activate_mlo_links");
LABEL_29:
    result = wlan_objmgr_vdev_release_ref(v83, 0x18u, v59, v60, v61, v62, v63, v64, v65, v66, v67);
    goto LABEL_30;
  }
  result = qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: vdev_id: %d vdev not found",
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "policy_mgr_activate_mlo_links",
             v5);
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
