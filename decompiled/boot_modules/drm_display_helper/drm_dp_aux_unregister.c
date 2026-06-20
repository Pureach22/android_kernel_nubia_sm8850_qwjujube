__int64 __fastcall drm_dp_aux_unregister(__int64 a1)
{
  return i2c_del_adapter(a1 + 8);
}
