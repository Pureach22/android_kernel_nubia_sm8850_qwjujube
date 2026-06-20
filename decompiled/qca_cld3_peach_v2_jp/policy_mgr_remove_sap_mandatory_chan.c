__int64 __fastcall policy_mgr_remove_sap_mandatory_chan(__int64 a1, int a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned __int64 v13; // x4
  __int64 result; // x0
  unsigned __int64 v15; // x8
  unsigned int v16; // w20
  int v17; // w11
  size_t v18; // x1
  __int64 v19; // x19
  _DWORD v20[102]; // [xsp+0h] [xbp-1A0h] BYREF
  __int64 v21; // [xsp+198h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v20, 0, sizeof(v20));
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( comp_private_obj )
  {
    v13 = *(unsigned int *)(comp_private_obj + 960);
    if ( (unsigned int)v13 <= 0x65 )
    {
      if ( (_DWORD)v13 )
      {
        v15 = 0;
        v16 = 0;
        do
        {
          if ( v15 == 102 )
LABEL_16:
            __break(0x5512u);
          v17 = *(_DWORD *)(comp_private_obj + 552 + 4 * v15);
          if ( v17 != a2 )
          {
            if ( v16 > 0x65 )
              goto LABEL_16;
            v20[v16++] = v17;
          }
          ++v15;
        }
        while ( v15 < v13 );
        v18 = (unsigned int)(4 * v13);
      }
      else
      {
        v16 = 0;
        v18 = 0;
      }
      v19 = comp_private_obj;
      qdf_mem_set((void *)(comp_private_obj + 552), v18, 0);
      result = (__int64)qdf_mem_copy((void *)(v19 + 552), v20, 4 * v16);
      *(_DWORD *)(v19 + 960) = v16;
    }
    else
    {
      result = qdf_trace_msg(
                 0x4Fu,
                 2u,
                 "%s: Invalid channel len %d ",
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 "policy_mgr_remove_sap_mandatory_chan");
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid Context",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "policy_mgr_remove_sap_mandatory_chan");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
