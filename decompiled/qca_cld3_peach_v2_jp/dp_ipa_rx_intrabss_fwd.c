__int64 __fastcall dp_ipa_rx_intrabss_fwd(__int64 a1, unsigned __int8 a2, __int64 a3, __int64 a4)
{
  unsigned __int8 v6; // w23
  char v8; // w24
  __int64 ref_by_id_2; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  _DWORD *v19; // x8
  __int64 v20; // x4
  unsigned int *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  unsigned int *v31; // x8
  __int64 v32; // x23
  __int64 v33; // x0
  unsigned int v34; // w21
  __int64 v35; // x0
  unsigned int *v36; // x8
  __int64 v37; // x23
  __int64 v38; // x24
  unsigned __int16 *v39; // x25
  __int64 v40; // x0
  __int64 v41; // x0
  int v43[2]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v44; // [xsp+10h] [xbp-10h]
  __int64 v45; // [xsp+18h] [xbp-8h]

  v6 = a2;
  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_BYTE *)(a3 + 41);
  ref_by_id_2 = dp_vdev_get_ref_by_id_2(a1, a2);
  v18 = ref_by_id_2;
  if ( (v8 & 2) == 0 )
  {
    if ( ref_by_id_2 )
    {
      v19 = *(_DWORD **)(a1 + 1640);
      *(_QWORD *)v43 = 0;
      v44 = 0;
      if ( v19 )
      {
        v20 = *(_QWORD *)(a3 + 224);
        if ( *(v19 - 1) != 259406424 )
          __break(0x8228u);
        if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, __int64, int *))v19)(
                a1,
                ref_by_id_2,
                0,
                0,
                v20,
                v43)
            & 1) == 0 )
          goto LABEL_24;
        v30 = *(_QWORD *)v43;
        v6 = v44;
      }
      else
      {
        v30 = a1;
        *(_QWORD *)v43 = a1;
        LOBYTE(v44) = v6;
      }
      v35 = dp_vdev_get_ref_by_id_2(v30, v6);
      if ( v35 )
      {
        v36 = (unsigned int *)*(unsigned int *)(v35 + 32);
        v37 = v35;
        if ( (_DWORD)v36 != 3
          && (v38 = *(_QWORD *)(v35 + 24)) != 0
          && (v39 = *(unsigned __int16 **)(a3 + 224), (unsigned int)qdf_mem_cmp(v39, (const void *)(v35 + 96), 6u))
          && (v40 = dp_peer_find_hash_find(*(__int64 *)v43, v39, 0, *(_BYTE *)(v37 + 59), 0xEu)) != 0
          && (dp_peer_unref_delete(v40, 0xEu, v22, v23, v24, v25, v26, v27, v28, v29),
              (v41 = dp_peer_find_hash_find(a1, v39 + 3, 0, *(_BYTE *)(v18 + 59), 0xEu)) != 0) )
        {
          dp_peer_unref_delete(v41, 0xEu, v22, v23, v24, v25, v26, v27, v28, v29);
          v22 = dp_ipa_intrabss_send(v38, v37, a3, a4);
          v34 = 1;
        }
        else
        {
          v34 = 0;
        }
        dp_vdev_unref_delete(*(__int64 *)v43, v37, 0xEu, v36, v22, v23, v24, v25, v26, v27, v28, v29);
        goto LABEL_25;
      }
LABEL_24:
      v34 = 0;
LABEL_25:
      dp_vdev_unref_delete(a1, v18, 0xEu, v21, v22, v23, v24, v25, v26, v27, v28, v29);
      goto LABEL_26;
    }
LABEL_27:
    v34 = 0;
    goto LABEL_26;
  }
  if ( !ref_by_id_2 )
    goto LABEL_27;
  v31 = (unsigned int *)*(unsigned int *)(ref_by_id_2 + 32);
  if ( (_DWORD)v31 != 3 )
  {
    v32 = *(_QWORD *)(ref_by_id_2 + 24);
    if ( v32 )
    {
      v33 = skb_copy(a3, 2080);
      if ( v33 )
        v10 = dp_ipa_intrabss_send(v32, v18, v33, a4);
    }
  }
  dp_vdev_unref_delete(a1, v18, 0xEu, v31, v10, v11, v12, v13, v14, v15, v16, v17);
  v34 = 0;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v34;
}
