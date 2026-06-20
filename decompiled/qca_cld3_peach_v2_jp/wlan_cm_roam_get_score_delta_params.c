__int64 __fastcall wlan_cm_roam_get_score_delta_params(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    a2[8] = *(_QWORD *)(result + 6396);
    a2[9] = *(_QWORD *)(result + 6404);
    a2[10] = *(_QWORD *)(result + 6412);
    a2[11] = *(_QWORD *)(result + 6420);
    a2[12] = *(_QWORD *)(result + 6428);
    a2[13] = *(_QWORD *)(result + 6436);
    a2[14] = *(_QWORD *)(result + 6444);
    a2[15] = *(_QWORD *)(result + 6452);
    a2[16] = *(_QWORD *)(result + 6460);
    a2[17] = *(_QWORD *)(result + 6468);
    a2[18] = *(_QWORD *)(result + 6476);
    a2[19] = *(_QWORD *)(result + 6484);
    a2[20] = *(_QWORD *)(result + 6492);
    a2[21] = *(_QWORD *)(result + 6500);
    a2[22] = *(_QWORD *)(result + 6508);
    a2[23] = *(_QWORD *)(result + 6516);
    a2[24] = *(_QWORD *)(result + 6524);
    a2[25] = *(_QWORD *)(result + 6532);
    a2[26] = *(_QWORD *)(result + 6540);
    a2[27] = *(_QWORD *)(result + 6548);
  }
  return result;
}
