void __fastcall target_if_ndp_confirm_handler(__int64 a1)
{
  __int64 psoc_from_scn_hdl; // x0
  __int64 v2; // x8
  __int64 v3; // x21
  unsigned int ndp_confirm; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  _ReadStatusReg(SP_EL0);
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( psoc_from_scn_hdl )
  {
    v2 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
    if ( v2 )
    {
      v3 = *(_QWORD *)(v2 + 16);
      if ( v3 )
      {
        if ( _qdf_mem_malloc(0x190u, "target_if_ndp_confirm_handler", 386) )
        {
          ndp_confirm = wmi_extract_ndp_confirm(v3);
          if ( ndp_confirm )
          {
            qdf_trace_msg(
              0x49u,
              2u,
              "%s: parsing of event failed, %d",
              v5,
              v6,
              v7,
              v8,
              v9,
              v10,
              v11,
              v12,
              "target_if_ndp_confirm_handler",
              ndp_confirm);
            JUMPOUT(0x5A8548);
          }
          JUMPOUT(0x5A8440);
        }
        JUMPOUT(0x5A8438);
      }
    }
    JUMPOUT(0x5A83E4);
  }
  JUMPOUT(0x5A83EC);
}
