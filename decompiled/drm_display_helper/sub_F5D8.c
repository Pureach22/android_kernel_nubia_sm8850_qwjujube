void sub_F5D8()
{
  __int64 v0; // x19
  __int64 v1; // x20
  unsigned __int64 StatusReg; // x21
  __int64 v3; // x22
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &drm_dp_decode_sideband_req__alloc_tag_14;
  v4 = kmemdup_noprof(v1 + 4, *(unsigned __int8 *)(v0 + 10), 3264);
  *(_QWORD *)(StatusReg + 80) = v3;
  *(_QWORD *)(v0 + 16) = v4;
  if ( !v4 )
    JUMPOUT(0xF4E0);
  JUMPOUT(0xF394);
}
