__int64 __fastcall drm_dp_aux_init(__int64 a1)
{
  __int64 result; // x0

  _mutex_init(a1 + 1272, "&aux->hw_mutex", &drm_dp_aux_init___key);
  result = _mutex_init(a1 + 1384, "&aux->cec.lock", &drm_dp_aux_init___key_36);
  *(_QWORD *)(a1 + 1320) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 1328) = a1 + 1328;
  *(_QWORD *)(a1 + 1336) = a1 + 1328;
  *(_QWORD *)(a1 + 1344) = drm_dp_aux_crc_work;
  *(_QWORD *)(a1 + 24) = &drm_dp_i2c_algo;
  *(_QWORD *)(a1 + 32) = a1;
  *(_DWORD *)(a1 + 116) = 3;
  *(_QWORD *)(a1 + 40) = drm_dp_i2c_lock_ops;
  return result;
}
