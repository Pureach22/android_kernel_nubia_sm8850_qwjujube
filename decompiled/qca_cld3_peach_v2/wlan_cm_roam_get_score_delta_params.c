__int64 __fastcall wlan_cm_roam_get_score_delta_params(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    a2[8] = *(_QWORD *)(result + 6612);
    a2[9] = *(_QWORD *)(result + 6620);
    a2[10] = *(_QWORD *)(result + 6628);
    a2[11] = *(_QWORD *)(result + 6636);
    a2[12] = *(_QWORD *)(result + 6644);
    a2[13] = *(_QWORD *)(result + 6652);
    a2[14] = *(_QWORD *)(result + 6660);
    a2[15] = *(_QWORD *)(result + 6668);
    a2[16] = *(_QWORD *)(result + 6676);
    a2[17] = *(_QWORD *)(result + 6684);
    a2[18] = *(_QWORD *)(result + 6692);
    a2[19] = *(_QWORD *)(result + 6700);
    a2[20] = *(_QWORD *)(result + 6708);
    a2[21] = *(_QWORD *)(result + 6716);
    a2[22] = *(_QWORD *)(result + 6724);
    a2[23] = *(_QWORD *)(result + 6732);
    a2[24] = *(_QWORD *)(result + 6740);
    a2[25] = *(_QWORD *)(result + 6748);
    a2[26] = *(_QWORD *)(result + 6756);
    a2[27] = *(_QWORD *)(result + 6764);
  }
  return result;
}
