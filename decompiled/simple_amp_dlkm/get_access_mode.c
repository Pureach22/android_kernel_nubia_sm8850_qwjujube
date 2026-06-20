__int64 __fastcall get_access_mode(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v4; // w9
  _DWORD *v5; // x8
  int v6; // w9
  unsigned int v7; // w9
  __int64 v8; // x8

  result = 3;
  if ( a1 && (a2 & 0xFE040000) == 0x40000000 )
  {
    result = 2;
    switch ( a2 )
    {
      case 0x40580001u:
      case 0x40580002u:
      case 0x40580003u:
      case 0x40580004u:
      case 0x40580005u:
      case 0x40580006u:
      case 0x40580007u:
      case 0x40580008u:
      case 0x40580009u:
      case 0x4058000Au:
      case 0x4058000Bu:
      case 0x4058000Cu:
      case 0x4058000Du:
      case 0x4058000Eu:
      case 0x4058000Fu:
      case 0x40580010u:
      case 0x40580013u:
      case 0x40580014u:
      case 0x40580015u:
      case 0x40580016u:
      case 0x40580017u:
      case 0x40580020u:
      case 0x40580021u:
      case 0x40580022u:
      case 0x40580023u:
      case 0x40580024u:
      case 0x40580025u:
      case 0x40580026u:
      case 0x40580027u:
      case 0x40580028u:
      case 0x40580029u:
      case 0x4058002Au:
      case 0x4058002Bu:
      case 0x4058002Cu:
      case 0x4058002Du:
      case 0x4058002Eu:
      case 0x4058002Fu:
      case 0x40580030u:
      case 0x40580031u:
      case 0x40580032u:
      case 0x40580033u:
      case 0x40580034u:
      case 0x40580038u:
      case 0x40580039u:
      case 0x4058003Au:
      case 0x4058003Bu:
      case 0x4058003Cu:
      case 0x4058003Du:
      case 0x40580050u:
      case 0x40580051u:
      case 0x40580052u:
      case 0x40580053u:
      case 0x40580054u:
      case 0x40580055u:
      case 0x40580056u:
      case 0x40580057u:
      case 0x40580058u:
      case 0x40580059u:
      case 0x4058005Au:
      case 0x4058005Bu:
      case 0x4058005Cu:
      case 0x4058005Du:
      case 0x4058005Eu:
      case 0x4058005Fu:
      case 0x40580060u:
      case 0x40580061u:
      case 0x40580062u:
      case 0x40580063u:
      case 0x40580064u:
      case 0x40580065u:
      case 0x40580066u:
      case 0x40580067u:
      case 0x40580068u:
      case 0x40580069u:
      case 0x4058006Au:
      case 0x4058006Bu:
      case 0x4058006Cu:
      case 0x4058006Du:
      case 0x4058006Eu:
      case 0x4058006Fu:
      case 0x40580090u:
      case 0x40580091u:
      case 0x40580092u:
      case 0x40580093u:
      case 0x40580094u:
      case 0x40580095u:
      case 0x40580096u:
      case 0x40580097u:
      case 0x40580098u:
      case 0x40580099u:
      case 0x4058009Cu:
      case 0x4058009Du:
      case 0x405800B0u:
      case 0x405800B1u:
      case 0x405800B2u:
      case 0x405800B3u:
      case 0x405800B4u:
      case 0x405800B5u:
      case 0x405800B6u:
      case 0x405800B7u:
      case 0x405800B8u:
      case 0x405800B9u:
      case 0x405800BAu:
      case 0x405800BBu:
      case 0x405800BCu:
      case 0x405800BDu:
      case 0x405800BEu:
      case 0x405800BFu:
      case 0x405800C0u:
      case 0x405800C1u:
      case 0x405800C2u:
      case 0x405800C3u:
      case 0x405800C4u:
      case 0x405800C5u:
      case 0x405800C6u:
      case 0x405800C7u:
      case 0x405800C8u:
      case 0x405800C9u:
      case 0x405800CAu:
      case 0x405800CBu:
      case 0x405800CCu:
      case 0x405800CDu:
      case 0x405800CEu:
      case 0x405800CFu:
      case 0x405800D0u:
      case 0x405800D1u:
      case 0x405800D2u:
      case 0x405800D3u:
      case 0x40580101u:
      case 0x40580102u:
      case 0x40580103u:
      case 0x40580104u:
      case 0x40580105u:
      case 0x40580106u:
      case 0x40580107u:
      case 0x40580108u:
      case 0x40580109u:
      case 0x4058010Au:
      case 0x4058010Bu:
      case 0x4058010Cu:
      case 0x4058010Du:
      case 0x4058010Eu:
      case 0x4058010Fu:
      case 0x40580110u:
      case 0x40580111u:
      case 0x40580112u:
      case 0x40580113u:
      case 0x40580114u:
      case 0x40580115u:
      case 0x40580116u:
      case 0x40580117u:
      case 0x40580118u:
      case 0x40580119u:
      case 0x4058011Au:
      case 0x4058011Bu:
      case 0x4058011Cu:
      case 0x4058011Du:
      case 0x4058011Eu:
      case 0x4058011Fu:
      case 0x40580120u:
      case 0x40580121u:
      case 0x40580122u:
      case 0x40580123u:
      case 0x40580124u:
      case 0x40580125u:
      case 0x40580126u:
      case 0x40580127u:
      case 0x40580128u:
      case 0x40580129u:
      case 0x4058012Au:
      case 0x4058012Bu:
      case 0x4058012Cu:
      case 0x4058012Du:
      case 0x4058012Eu:
      case 0x4058012Fu:
      case 0x40580130u:
      case 0x40580131u:
      case 0x40580132u:
      case 0x40580133u:
      case 0x40580134u:
      case 0x40580135u:
      case 0x40580136u:
      case 0x40580137u:
      case 0x40580138u:
      case 0x40580139u:
      case 0x4058013Au:
      case 0x4058013Bu:
      case 0x4058013Cu:
      case 0x40580410u:
      case 0x40580411u:
      case 0x40580412u:
      case 0x40580413u:
      case 0x40580414u:
      case 0x40580415u:
      case 0x40580416u:
      case 0x40580417u:
      case 0x40580418u:
      case 0x40580419u:
      case 0x4058041Au:
      case 0x4058041Bu:
      case 0x4058041Cu:
      case 0x4058041Du:
      case 0x4058041Eu:
      case 0x4058041Fu:
      case 0x40580420u:
      case 0x40580421u:
      case 0x40580422u:
      case 0x40580423u:
      case 0x40580424u:
      case 0x40580425u:
      case 0x40580426u:
      case 0x4058042Au:
      case 0x4058042Bu:
      case 0x4058042Cu:
      case 0x4058042Du:
      case 0x4058042Eu:
      case 0x4058042Fu:
      case 0x40580434u:
      case 0x40580435u:
      case 0x40580436u:
      case 0x40580437u:
      case 0x40580438u:
      case 0x40580439u:
      case 0x40580441u:
      case 0x40580442u:
      case 0x40580443u:
      case 0x40580444u:
      case 0x40580445u:
      case 0x40580446u:
      case 0x40580447u:
      case 0x40580448u:
      case 0x40580449u:
      case 0x4058044Au:
      case 0x4058044Bu:
      case 0x4058044Cu:
      case 0x4058044Du:
      case 0x4058044Eu:
      case 0x4058044Fu:
      case 0x40580450u:
      case 0x40580451u:
      case 0x40580456u:
      case 0x40580457u:
      case 0x40580458u:
      case 0x40580459u:
      case 0x40580504u:
      case 0x40580505u:
      case 0x40580506u:
      case 0x40580510u:
      case 0x40580511u:
      case 0x40580512u:
      case 0x40580514u:
      case 0x40580515u:
      case 0x40580516u:
      case 0x40580517u:
      case 0x40580518u:
      case 0x40580519u:
      case 0x4058051Au:
      case 0x4058051Bu:
      case 0x4058051Cu:
      case 0x4058051Du:
      case 0x4058051Eu:
      case 0x4058051Fu:
      case 0x40580520u:
      case 0x40580530u:
      case 0x40580532u:
      case 0x40580534u:
      case 0x40580535u:
      case 0x40580536u:
      case 0x40580537u:
      case 0x40580538u:
      case 0x40580539u:
      case 0x4058053Au:
      case 0x4058053Bu:
      case 0x4058053Cu:
      case 0x4058053Du:
      case 0x4058053Eu:
      case 0x4058053Fu:
      case 0x40580540u:
      case 0x40580541u:
      case 0x40580542u:
      case 0x40580543u:
      case 0x40580544u:
      case 0x40580545u:
      case 0x40580546u:
      case 0x40580547u:
      case 0x40580548u:
      case 0x40580549u:
      case 0x4058054Au:
      case 0x4058054Bu:
      case 0x4058054Cu:
      case 0x4058054Du:
      case 0x4058054Eu:
      case 0x4058054Fu:
      case 0x40580550u:
      case 0x40580551u:
      case 0x40580552u:
      case 0x40580553u:
      case 0x40580554u:
      case 0x40580555u:
      case 0x40580556u:
      case 0x40580557u:
      case 0x40580558u:
      case 0x40580559u:
      case 0x4058055Au:
      case 0x4058055Bu:
      case 0x4058055Cu:
      case 0x40580560u:
      case 0x40580561u:
      case 0x40580562u:
      case 0x40580563u:
      case 0x40580564u:
      case 0x40580565u:
      case 0x40580566u:
      case 0x40580567u:
      case 0x40580568u:
      case 0x40580569u:
      case 0x4058056Au:
      case 0x4058056Bu:
      case 0x4058056Cu:
      case 0x4058056Du:
      case 0x4058056Eu:
      case 0x4058056Fu:
      case 0x40580570u:
      case 0x40580571u:
      case 0x40580572u:
      case 0x40580573u:
      case 0x40580574u:
      case 0x40580575u:
      case 0x40580576u:
      case 0x40580577u:
      case 0x40580578u:
      case 0x40580579u:
      case 0x4058057Au:
      case 0x4058057Bu:
      case 0x4058057Cu:
      case 0x40580580u:
      case 0x40580581u:
      case 0x40580582u:
      case 0x40580583u:
      case 0x40580587u:
      case 0x40580588u:
      case 0x40580589u:
      case 0x4058058Au:
      case 0x4058058Bu:
      case 0x4058058Cu:
      case 0x4058058Du:
      case 0x4058058Eu:
      case 0x4058058Fu:
      case 0x40580590u:
      case 0x40580591u:
      case 0x40580592u:
      case 0x40580593u:
      case 0x40580594u:
      case 0x40580595u:
      case 0x40580596u:
      case 0x40580597u:
      case 0x40580598u:
      case 0x40580599u:
      case 0x4058059Au:
      case 0x4058059Bu:
      case 0x4058059Cu:
      case 0x4058059Du:
      case 0x4058059Eu:
      case 0x4058059Fu:
      case 0x405805A0u:
      case 0x405805A1u:
      case 0x405805A2u:
      case 0x405805A3u:
      case 0x405805A4u:
      case 0x405805A5u:
      case 0x405805A6u:
      case 0x405805A7u:
      case 0x405805A8u:
      case 0x405805A9u:
      case 0x405805AAu:
      case 0x405805ABu:
      case 0x405805ACu:
      case 0x405805ADu:
      case 0x405805AEu:
      case 0x405805AFu:
      case 0x405805B0u:
      case 0x405805B1u:
      case 0x405805B2u:
      case 0x405805B3u:
      case 0x405805B4u:
      case 0x405805B5u:
      case 0x405805B6u:
      case 0x405805B7u:
      case 0x405805B8u:
      case 0x405805B9u:
      case 0x405805BAu:
      case 0x405805BBu:
      case 0x405805BCu:
      case 0x405805BDu:
      case 0x405805BEu:
      case 0x405805BFu:
      case 0x405805C0u:
      case 0x405805C3u:
      case 0x405805C4u:
      case 0x405805C5u:
      case 0x405805C6u:
      case 0x405805C7u:
      case 0x405805C8u:
      case 0x405805C9u:
      case 0x405805CAu:
      case 0x405805CBu:
      case 0x405805CCu:
      case 0x405805CDu:
      case 0x405805CEu:
      case 0x405805CFu:
      case 0x405805D0u:
      case 0x405805D1u:
      case 0x405805D2u:
      case 0x405805D3u:
      case 0x405805D4u:
      case 0x405805F1u:
      case 0x405805F2u:
      case 0x405805F3u:
      case 0x40580601u:
      case 0x40580602u:
      case 0x40580603u:
      case 0x40580604u:
      case 0x40580605u:
      case 0x40580606u:
      case 0x40580607u:
      case 0x40580608u:
      case 0x40580609u:
      case 0x4058060Au:
      case 0x4058060Bu:
      case 0x4058060Cu:
      case 0x4058060Du:
      case 0x4058060Eu:
      case 0x4058060Fu:
      case 0x40580610u:
      case 0x40580611u:
      case 0x40580612u:
      case 0x40580613u:
      case 0x40580621u:
      case 0x40580622u:
      case 0x40580623u:
      case 0x40580624u:
      case 0x40580625u:
      case 0x40580626u:
      case 0x40580627u:
      case 0x40580628u:
      case 0x40580629u:
      case 0x4058062Au:
      case 0x4058062Bu:
      case 0x4058062Cu:
      case 0x4058062Du:
      case 0x4058062Eu:
      case 0x4058062Fu:
      case 0x40580630u:
      case 0x40580631u:
      case 0x40580632u:
      case 0x40580633u:
      case 0x40580640u:
      case 0x40580641u:
      case 0x40580642u:
      case 0x40580643u:
      case 0x40580644u:
      case 0x40580645u:
      case 0x40580647u:
      case 0x40580648u:
      case 0x40580649u:
      case 0x4058064Au:
      case 0x4058064Bu:
      case 0x4058064Cu:
      case 0x4058064Du:
      case 0x4058064Eu:
      case 0x4058064Fu:
      case 0x40580650u:
      case 0x40580651u:
      case 0x40580652u:
      case 0x40580653u:
      case 0x40580654u:
      case 0x40580655u:
      case 0x40580656u:
      case 0x40580660u:
      case 0x40580661u:
      case 0x40580662u:
      case 0x40580663u:
      case 0x40580664u:
      case 0x40580665u:
      case 0x40580667u:
      case 0x40580668u:
      case 0x40580669u:
      case 0x4058066Au:
      case 0x4058066Bu:
      case 0x4058066Cu:
      case 0x4058066Du:
      case 0x4058066Eu:
      case 0x4058066Fu:
      case 0x40580670u:
      case 0x40580671u:
      case 0x40580672u:
      case 0x40580673u:
      case 0x40580674u:
      case 0x40580675u:
      case 0x40580676u:
      case 0x40580680u:
      case 0x40580681u:
      case 0x40580682u:
      case 0x40580683u:
      case 0x40580684u:
      case 0x405806A1u:
      case 0x405806A9u:
      case 0x405806B1u:
      case 0x405806B9u:
      case 0x405806C1u:
      case 0x405806C2u:
      case 0x405806C3u:
      case 0x405806C4u:
      case 0x405806C5u:
      case 0x405806C6u:
      case 0x405806C7u:
      case 0x405806C8u:
      case 0x405806C9u:
      case 0x405806CAu:
      case 0x405806CBu:
      case 0x405806CCu:
      case 0x405806CDu:
      case 0x405806CEu:
      case 0x405806D0u:
      case 0x405806D1u:
      case 0x405806D2u:
      case 0x405808FFu:
        return result;
      case 0x40580011u:
      case 0x40580012u:
      case 0x40580035u:
      case 0x40580036u:
      case 0x40580037u:
      case 0x4058009Au:
      case 0x4058009Bu:
      case 0x405800D4u:
      case 0x405800D5u:
      case 0x405800D6u:
      case 0x405800D7u:
      case 0x405800D8u:
      case 0x405800D9u:
      case 0x405800DAu:
      case 0x405800DBu:
      case 0x405800DCu:
      case 0x405800DDu:
      case 0x405800DEu:
      case 0x405800DFu:
      case 0x405800E0u:
      case 0x405800E1u:
      case 0x405800E2u:
      case 0x405800E3u:
      case 0x405800E4u:
      case 0x405800E5u:
      case 0x405800E6u:
      case 0x405800E7u:
      case 0x405800E8u:
      case 0x405800E9u:
      case 0x4058013Du:
      case 0x4058013Eu:
      case 0x4058013Fu:
      case 0x40580140u:
      case 0x40580141u:
      case 0x40580142u:
      case 0x40580143u:
      case 0x40580144u:
      case 0x40580401u:
      case 0x40580402u:
      case 0x40580403u:
      case 0x40580404u:
      case 0x40580405u:
      case 0x40580427u:
      case 0x40580428u:
      case 0x40580429u:
      case 0x40580430u:
      case 0x40580431u:
      case 0x40580432u:
      case 0x4058043Au:
      case 0x4058043Bu:
      case 0x4058043Cu:
      case 0x40580452u:
      case 0x40580453u:
      case 0x40580454u:
      case 0x40580455u:
      case 0x4058045Au:
      case 0x4058045Bu:
      case 0x4058045Cu:
      case 0x4058045Du:
      case 0x4058045Eu:
      case 0x4058045Fu:
      case 0x40580501u:
      case 0x40580509u:
      case 0x40580513u:
      case 0x40580521u:
      case 0x40580531u:
      case 0x40580533u:
      case 0x4058055Du:
      case 0x4058057Du:
      case 0x40580584u:
      case 0x40580585u:
      case 0x40580586u:
      case 0x405805C1u:
      case 0x405805F0u:
      case 0x40580657u:
      case 0x40580658u:
      case 0x40580666u:
      case 0x40580677u:
      case 0x40580678u:
      case 0x405806CFu:
        return 0;
      default:
        result = 2;
        if ( a2 - 1079510112 < 0x6D || a2 - 1079511168 < 0x49 )
          return result;
        if ( (a2 & 0x339000) != 0 )
          goto LABEL_37;
        v4 = (a2 >> 22) & 7;
        if ( v4 - 1 > 2 )
          goto LABEL_37;
        v5 = *(_DWORD **)(a1 + 8LL * v4 + 48);
        if ( !v5 )
          goto LABEL_37;
        v6 = (a2 >> 7) & 0x1F;
        if ( *v5 == v6 )
        {
          v7 = 0;
        }
        else if ( v5[12] == v6 )
        {
          v7 = 1;
        }
        else if ( v5[24] == v6 )
        {
          v7 = 2;
        }
        else if ( v5[36] == v6 )
        {
          v7 = 3;
        }
        else if ( v5[48] == v6 )
        {
          v7 = 4;
        }
        else if ( v5[60] == v6 )
        {
          v7 = 5;
        }
        else if ( v5[72] == v6 )
        {
          v7 = 6;
        }
        else if ( v5[84] == v6 )
        {
          v7 = 7;
        }
        else if ( v5[96] == v6 )
        {
          v7 = 8;
        }
        else if ( v5[108] == v6 )
        {
          v7 = 9;
        }
        else if ( v5[120] == v6 )
        {
          v7 = 10;
        }
        else
        {
          if ( v5[132] != v6 )
            goto LABEL_37;
          v7 = 11;
        }
        v8 = *(_QWORD *)(*(_QWORD *)&v5[12 * v7 + 10] + 8LL * ((a2 >> 15) & 0x10 | (a2 >> 3) & 0xF));
        if ( v8 )
          return *(unsigned int *)(v8 + 4);
LABEL_37:
        result = 3;
        break;
    }
  }
  return result;
}
