__int64 __fastcall nan_serialized_cb(
        int *a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v10; // x19
  __int64 result; // x0
  const char *v13; // x2
  const char *v14; // x3
  int v15; // w4
  unsigned int v16; // w8
  __int64 v17; // x21
  __int64 v18; // x9
  __int64 v19; // x0
  unsigned int v20; // w20
  int v21; // w22
  __int64 comp_private_obj; // x0
  _DWORD *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int *v32; // x8
  const char *v33; // x2
  unsigned int v34; // w1
  _QWORD v35[5]; // [xsp+8h] [xbp-28h] BYREF

  v35[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v10 = *((__int64 **)a1 + 5)) == nullptr )
  {
    qdf_trace_msg(0x53u, 1u, "%s: cmd or umac_cmd is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_serialized_cb");
    result = 29;
    goto LABEL_33;
  }
  result = 0;
  if ( a2 <= 1 )
  {
    if ( a2 )
    {
      if ( a2 != 1 )
        goto LABEL_10;
      goto LABEL_33;
    }
    v15 = *a1;
    v16 = *a1 - 6;
    if ( v16 >= 5 )
    {
      v13 = "%s: in correct cmdtype: %d";
      v14 = "nan_req_activated";
      goto LABEL_24;
    }
    v17 = *v10;
    if ( *v10 )
    {
      v18 = *(_QWORD *)(v17 + 152);
      if ( v18 )
      {
        v19 = *(_QWORD *)(v18 + 80);
        if ( v19 )
        {
          v20 = dword_A2B5D8[v16];
          v21 = v15;
          comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v19, 0xFu);
          if ( comp_private_obj )
          {
            v23 = *(_DWORD **)(comp_private_obj + 248);
            if ( *(v23 - 1) != -297509796 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64 *, _QWORD))v23)(v10, v20);
            if ( v21 == 10 )
            {
              v35[0] = 0xA0000000FLL;
              v35[1] = 0x800000000LL;
              v35[2] = v17;
              v35[3] = 1;
              wlan_serialization_remove_cmd((unsigned int *)v35, v24, v25, v26, v27, v28, v29, v30, v31);
            }
            goto LABEL_32;
          }
          v33 = "%s: psoc_nan_obj is null";
          v34 = 2;
          goto LABEL_31;
        }
      }
      v33 = "%s: psoc is null";
    }
    else
    {
      v33 = "%s: vdev is null";
    }
    v34 = 1;
LABEL_31:
    qdf_trace_msg(0x53u, v34, v33, a3, a4, a5, a6, a7, a8, a9, a10, "nan_req_activated");
    goto LABEL_32;
  }
  if ( a2 == 2 )
  {
    v32 = (unsigned int *)(unsigned int)(*a1 - 6);
    if ( (unsigned int)v32 >= 5 )
    {
      qdf_trace_msg(0x53u, 2u, "%s: invalid req type: %d", a3, a4, a5, a6, a7, a8, a9, a10, "nan_release_cmd");
    }
    else if ( *v10 )
    {
      wlan_objmgr_vdev_release_ref(*v10, 0x14u, v32, a3, a4, a5, a6, a7, a8, a9, a10);
LABEL_27:
      _qdf_mem_free((__int64)v10);
      goto LABEL_32;
    }
    qdf_trace_msg(0x53u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_release_cmd");
    goto LABEL_27;
  }
  if ( a2 != 3 )
  {
LABEL_10:
    v13 = "%s: invalid serialized cb reason: %d";
    v14 = "nan_serialized_cb";
LABEL_24:
    qdf_trace_msg(0x53u, 1u, v13, a3, a4, a5, a6, a7, a8, a9, a10, v14);
LABEL_32:
    result = 0;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
