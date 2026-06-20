__int64 __fastcall wlan_mlme_get_edca_params(
        unsigned int *a1,
        void *a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  size_t v12; // x2
  const void *v13; // x1
  __int64 result; // x0

  switch ( a3 )
  {
    case 0:
      v12 = a1[12];
      v13 = a1 + 14;
      goto LABEL_26;
    case 1:
      v12 = a1[2];
      v13 = a1 + 4;
      goto LABEL_26;
    case 2:
      v12 = a1[22];
      v13 = a1 + 24;
      goto LABEL_26;
    case 3:
      v12 = a1[32];
      v13 = a1 + 34;
      goto LABEL_26;
    case 4:
      v12 = a1[52];
      v13 = a1 + 54;
      goto LABEL_26;
    case 5:
      v12 = a1[42];
      v13 = a1 + 44;
      goto LABEL_26;
    case 6:
      v12 = a1[62];
      v13 = a1 + 64;
      goto LABEL_26;
    case 7:
      v12 = a1[72];
      v13 = a1 + 74;
      goto LABEL_26;
    case 8:
      v12 = a1[92];
      v13 = a1 + 94;
      goto LABEL_26;
    case 9:
      v12 = a1[82];
      v13 = a1 + 84;
      goto LABEL_26;
    case 10:
      v12 = a1[102];
      v13 = a1 + 104;
      goto LABEL_26;
    case 11:
      v12 = a1[112];
      v13 = a1 + 114;
      goto LABEL_26;
    case 12:
      v12 = a1[132];
      v13 = a1 + 134;
      goto LABEL_26;
    case 13:
      v12 = a1[122];
      v13 = a1 + 124;
      goto LABEL_26;
    case 14:
      v12 = a1[142];
      v13 = a1 + 144;
      goto LABEL_26;
    case 15:
      v12 = a1[152];
      v13 = a1 + 154;
      goto LABEL_26;
    case 16:
      v12 = a1[172];
      v13 = a1 + 174;
      goto LABEL_26;
    case 17:
      v12 = a1[162];
      v13 = a1 + 164;
      goto LABEL_26;
    case 18:
      v12 = a1[182];
      v13 = a1 + 184;
      goto LABEL_26;
    case 19:
      v12 = a1[192];
      v13 = a1 + 194;
      goto LABEL_26;
    case 20:
      v12 = a1[212];
      v13 = a1 + 214;
      goto LABEL_26;
    case 21:
      v12 = a1[202];
      v13 = a1 + 204;
      goto LABEL_26;
    case 22:
      v12 = a1[222];
      v13 = a1 + 224;
      goto LABEL_26;
    case 23:
      v12 = a1[232];
      v13 = a1 + 234;
LABEL_26:
      qdf_mem_copy(a2, v13, v12);
      result = 0;
      break;
    default:
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: Invalid edca access category",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_mlme_get_edca_params");
      result = 4;
      break;
  }
  return result;
}
