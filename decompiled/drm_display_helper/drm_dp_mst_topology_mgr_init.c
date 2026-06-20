__int64 __fastcall drm_dp_mst_topology_mgr_init(__int64 a1, __int64 a2, __int64 a3, int a4, int a5, int a6)
{
  __int64 v12; // x0
  __int64 v13; // x2

  _mutex_init(a1 + 800, "&mgr->lock", &drm_dp_mst_topology_mgr_init___key);
  _mutex_init(a1 + 936, "&mgr->qlock", &drm_dp_mst_topology_mgr_init___key_89);
  _mutex_init(a1 + 1120, "&mgr->delayed_destroy_lock", &drm_dp_mst_topology_mgr_init___key_91);
  _mutex_init(a1 + 1224, "&mgr->up_req_lock", &drm_dp_mst_topology_mgr_init___key_93);
  _mutex_init(a1 + 848, "&mgr->probe_lock", &drm_dp_mst_topology_mgr_init___key_95);
  *(_QWORD *)(a1 + 984) = a1 + 984;
  *(_QWORD *)(a1 + 992) = a1 + 984;
  *(_QWORD *)(a1 + 1088) = a1 + 1088;
  *(_QWORD *)(a1 + 1096) = a1 + 1088;
  *(_QWORD *)(a1 + 1104) = a1 + 1104;
  *(_QWORD *)(a1 + 1112) = a1 + 1104;
  *(_QWORD *)(a1 + 1208) = a1 + 1208;
  *(_QWORD *)(a1 + 1216) = a1 + 1208;
  v12 = alloc_workqueue("drm_dp_mst_wq", 131074, 1);
  *(_QWORD *)(a1 + 1168) = v12;
  if ( !v12 )
    return 4294967284LL;
  *(_QWORD *)(a1 + 1024) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 1032) = a1 + 1032;
  *(_QWORD *)(a1 + 1040) = a1 + 1032;
  *(_QWORD *)(a1 + 1048) = drm_dp_mst_link_probe_work;
  *(_QWORD *)(a1 + 1056) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 1064) = a1 + 1064;
  *(_QWORD *)(a1 + 1072) = a1 + 1064;
  *(_QWORD *)(a1 + 1080) = drm_dp_tx_work;
  *(_QWORD *)(a1 + 1176) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 1184) = a1 + 1184;
  *(_QWORD *)(a1 + 1192) = a1 + 1184;
  *(_QWORD *)(a1 + 1272) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 1200) = drm_dp_delayed_destroy_work;
  *(_QWORD *)(a1 + 1280) = a1 + 1280;
  *(_QWORD *)(a1 + 1288) = a1 + 1280;
  *(_QWORD *)(a1 + 1296) = drm_dp_mst_up_req_work;
  _init_waitqueue_head(a1 + 1000, "&mgr->tx_waitq", &drm_dp_mst_topology_mgr_init___key_102);
  *(_QWORD *)(a1 + 104) = a2;
  *(_QWORD *)(a1 + 128) = a3;
  *(_DWORD *)(a1 + 120) = a4;
  *(_DWORD *)(a1 + 136) = a5;
  *(_DWORD *)(a1 + 140) = a6;
  v13 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
  if ( !v13 )
    return 4294967284LL;
  *(_QWORD *)(v13 + 16) = a1;
  *(_WORD *)(v13 + 72) = 319;
  *(_QWORD *)(v13 + 56) = v13 + 56;
  *(_QWORD *)(v13 + 64) = v13 + 56;
  drm_atomic_private_obj_init(a2, a1);
  return 0;
}
